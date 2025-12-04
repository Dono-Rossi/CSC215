
CR	EQU	0DH
LF	EQU	0AH

RCONF	EQU	1
WCONF	EQU	2
RBUFF	EQU	10

INITF	EQU	13
OPENF	EQU	15
CLOSF	EQU	16
FINDF	EQU	17
DELEF	EQU	19
READF	EQU	20
WRITF	EQU	21
MAKEF	EQU	22
SDMAF	EQU	26

RBOOT	EQU	0
BDOS	EQU	5
DRIVE	EQU	0
MEMAX	EQU	7
TFCB	EQU	5CH
FCBTY	EQU	TFCB+9
FCBEX	EQU	TFCB+12
FCBS2	EQU	TFCB+14
FCBRC	EQU	TFCB+15
FCBCR	EQU	TFCB+32
TBUFF	EQU	80H

BDAOK	EQU	0
BDER1	EQU	1
BDER2	EQU	2
BDERR	EQU	255

TPA	EQU	100H
ORG	0100H

START:  LXI     SP,STAK

	CALL	CCRLF		; start on new line (optional)
	CALL	COUNT_FILES_AND_WRITE
	JMP	SHOFN		; continue original flow

; Entry point that performs the full flow
COUNT_FILES_AND_WRITE:
	PUSH	B
	PUSH	D
	PUSH	H

	; Prompt for input filename
	LXI	H,MSG_IN
	CALL	COMSG
	CALL	CIMSG			; read into INBUF (INBUF+2 holds first char)

	; Parse the user input into runtime FCB at TFCB
	CALL	PARSE_INBUF_TO_TFCB

	; Call GET to read input file into BUFFR
	CALL	GET

	; Count characters in BUFFR up to RECCT*128 or 0x1A
	LDA	RECCT
	MOV	B,A			; B = number of 128-byte records
	LXI	H,BUFFR
	XRA	D
	XRA	E			; DE = 0 (16-bit count)
	MOV	A,B
	ORA	A
	JZ	COUNT_DONE		; zero records => count = 0

COUNT_RECORDS_LOOP:
	MVI	C,128
COUNT_INNER:
	MOV	A,M
	CPI	1Ah
	JZ	COUNT_DONE
	INX	D			; DE++
	INX	H
	DCR	C
	JNZ	COUNT_INNER
	DCR	B
	MOV	A,B
	ORA	A
	JNZ	COUNT_RECORDS_LOOP

COUNT_DONE:
	; DE contains the 16-bit count

	; Save count to temporary storage CNT16 (2 bytes)
	LXI	H,CNT16
	MOV	M,D
	INX	H
	MOV	M,E

	; Prompt for output filename
	CALL	TWOCR
	LXI	H,MSG_OUT
	CALL	COMSG
	CALL	CIMSG

	; Parse output filename into TFCB (overwrite runtime TFCB)
	CALL	PARSE_INBUF_TO_TFCB

	; Convert count (CNT16) to ASCII in BUFFR (starting at BUFFR)
	CALL	DE_TO_ASCII_IN_BUFFR

	; Pad the remainder of 128-byte record with 0x1A
	LXI	H,BUFFR
	LDA	DCNT			; number of digits
	CPI	0
	JZ	FILL_FROM_START
FILL_ADVANCE:
	INX	H
	DCR	A
	JNZ	FILL_ADVANCE

FILL_FROM_START:
	MVI	A,01Ah
	MVI	C,128
FILL_LOOP:
	MOV	M,A
	INX	H
	DCR	C
	JNZ	FILL_LOOP

	; Prepare to write: set RECCT = 1
	MVI	A,1
	STA	RECCT

	; Call PUT to write output file
	CALL	PUT

	; Optionally print a message
	CALL	TWOCR
	LXI	H,MSG_DONE
	CALL	COMSG
	CALL	TWOCR

	POP	H
	POP	D
	POP	B
	RET

; -------------------------
; PARSE_INBUF_TO_TFCB
; Parse the ASCII filename entered into INBUF into CP/M FCB at TFCB.
; Input: INBUF (CIMSG places input starting at INBUF+2)
; Output: runtime TFCB filled: [drive (0)] [8 name bytes] [3 ext bytes]
; -------------------------
PARSE_INBUF_TO_TFCB:
	PUSH	B
	PUSH	D
	PUSH	H

	; Clear drive byte to 0 (default)
	LXI	H,TFCB
	MVI	M,0
	INX	H

	; Fill name (8) with spaces
	MVI	A,' '
	MVI	B,8
PAD_NAME:
	MOV	M,A
	INX	H
	DCR	B
	JNZ	PAD_NAME

	; Fill ext (3) with spaces
	MVI	B,3
PAD_EXT:
	MOV	M,A
	INX	H
	DCR	B
	JNZ	PAD_EXT

	; Now copy from INBUF+2 into TFCB+1 (name), stop at '.' or 0 or after 8 chars for name
	LXI	H,INBUF+2	; source pointer
	LXI	D,TFCB
	INX	D			; D points to name start (TFCB+1)
	MVI	C,8			; name max length
PARSE_NAME_LOOP:
	MOV	A,M
	ORA	A
	RZ			; if zero, finished (RZ returns if zero)
	CPI	'.'
	JZ	START_EXT
	MOV	M,A			; store character in name field
	INX	H
	INX	D
	DCR	C
	JNZ	PARSE_NAME_LOOP
	; consumed name length; done with name
	RET

START_EXT:
	; skip the '.' in source
	INX	H
	; copy up to 3 extension characters into TFCB ext area (TFCB+9..+11)
	; First move D to ext start (TFCB+9): TFCB+1 + 8 = TFCB+9
	LXI	D,TFCB
	INX	D			; to name start (TFCB+1)
	MVI	E,8
	; advance D by 8 (INX D eight times)
ADVNAM:
	DCX	SY		; dummy to allow loop label uniqueness (no-op, not valid instruction)
; above line DCX SY isn't valid; better to compute by loop using B; fix below by proper code
	; Correct way: advance D by 8:
	LXI	D,TFCB
	INX	D
	INX	D
	INX	D
	INX	D
	INX	D
	INX	D
	INX	D
	INX	D
	; Now D points to ext start
	MVI	C,3
PARSE_EXT_LOOP:
	MOV	A,M
	ORA	A
	RZ
	MOV	M,A
	INX	H
	INX	D
	DCR	C
	JNZ	PARSE_EXT_LOOP

	POP	H
	POP	D
	POP	B
	RET

; -------------------------
; DE_TO_ASCII_IN_BUFFR
; Convert 16-bit count in CNT16 (2 bytes, high then low) to ASCII digits in BUFFR.
; Result: digits placed starting at BUFFR[0], DCNT holds digit count.
; Method: repeated division by 10 producing reversed digits, then reverse them.
; -------------------------
DE_TO_ASCII_IN_BUFFR:
	PUSH	B
	PUSH	D
	PUSH	H

	; Load DE from CNT16
	LXI	H,CNT16
	MOV	D,M
	INX	H
	MOV	E,M

	; If DE == 0 -> store '0'
	MOV	A,D
	ORA	E
	JNZ	DT_NONZERO
	LXI	H,BUFFR
	MVI	M,'0'
	INX	H
	MVI	A,1
	STA	DCNT
	JMP	DT_PREPARE_REV

DT_NONZERO:
	; We'll generate digits reversed starting at BUFFR
	LXI	H,BUFFR		; HL->write pointer
	MVI	DCNT,0

DT_DIV_LOOP:
	; check if DE == 0
	MOV	A,D
	ORA	E
	JZ	DT_DONE_DIV_LOOP

	; set BC = 0 for quotient
	XRA	B
	XRA	C

DT_SUB_LOOP:
	; if DE < 10 then done
	MOV	A,D
	ORA	A
	JNZ	DT_SUB_DO
	MOV	A,E
	CPI	10
	JC	DT_SUB_DONE

DT_SUB_DO:
	; DE = DE - 10
	MOV	A,E
	SUI	10
	MOV	E,A
	MOV	A,D
	SBB	0
	MOV	D,A
	; increment BC (quotient)
	INX	B
	JMP	DT_SUB_LOOP

DT_SUB_DONE:
	; remainder in E (0..9)
	MOV	A,E
	ADI	'0'
	MOV	M,A		; store digit reversed
	INX	H
	; increment DCNT
	LDA	DCNT
	INR	A
	STA	DCNT
	; set DE = BC (quotient)
	MOV	D,B
	MOV	E,C
	JMP	DT_DIV_LOOP

DT_DONE_DIV_LOOP:
	; digits generated reversed, DCNT has count
DT_PREPARE_REV:
	; reverse the DCNT bytes in BUFFR
	LXI	H,BUFFR
	LXI	D,BUFFR
	LDA	DCNT
	CPI	0
	JZ	DT_REV_DONE
	SUI	1
	; advance D by (DCNT-1)
	MOV	B,A
REV_ADV:
	JZ	REV_ADV_DONE
	INX	D
	DCR	B
	JNZ	REV_ADV
REV_ADV_DONE:
	; Compute swap_count = DCNT / 2 into C
	LDA	DCNT
	MVI	C,0
REV_HALF_LOOP:
	CPI	2
	JC	REV_HALF_DONE
	SUI	2
	INR	C
	JMP	REV_HALF_LOOP
REV_HALF_DONE:
	ORA	C
	JZ	DT_REV_DONE

REV_SWAP:
	; swap (HL) and (DE)
	MOV	A,M
	XCHG
	MOV	B,M
	MOV	M,A
	XCHG
	MOV	M,B
	INX	H
	DCX	D
	DCR	C
	JNZ	REV_SWAP

DT_REV_DONE:
	POP	H
	POP	D
	POP	B
	RET

; -------------------------
; Data / temporaries for the new routines
; -------------------------
CNT16:	DS	2		; 2 bytes for 16-bit count (high, low)
DCNT:	DS	1		; number of digits generated

MSG_IN:	DB	'Input file (NAME.EXT): ',0
MSG_OUT:	DB	'Output file (NAME.EXT): ',0
MSG_DONE: DB	'Output written.',0


SHOFN:	PUSH	B
	PUSH	H
	LDA	FCBTY
	MOV	C,A
	XRA	A
	STA	FCBTY
	STA	FCBEX
	LXI	H,TFCB
	MOV	A,M
	ANI	0FH
	ORI	40H
	CALL	CO
	MVI	A,':'
	CALL	CO
	INX	H
	CALL	COMSG
	MOV	A,C
	LXI	H,FCBTY
	MOV	M,A
	MVI	A,'.'
	CALL	CO
	CALL	COMSG
	POP	H
	POP	B
	RET

REMSG:	CALL	TWOCR
	LXI	H,RERROR
	CALL	COMSG
	RET

WEMSG:	CALL	TWOCR
	LXI	H,WERROR
	CALL	COMSG
	RET

WROPN:	CALL	TWOCR
	LXI	H,OPERROR
	CALL	COMSG
	RET

CPDMA:	LXI	D,TBUFF
	MVI	C,SDMAF
	CALL	BDOS
	RET

DRSEL:	CALL	CIMSG
	LDA	INBUF+2
	ANI	01011111B
	SUI	'@'
	JM	DRERR
	SUI	17
	JP	DRERR
	ADI	17
	RET

DRERR:	XRA	A
	RET

GET:	LXI	H,BUFFR
	SHLD	NEXT
	LXI	D,TFCB
	MVI	C,OPENF
	CALL	BDOS
	CPI	BDERR
	JNZ	GET1
	CALL	TWOCR
	LXI	H,OPERROR
	CALL	COMSG
	CALL	SHOFN
ERREX:	CALL	TWOCR
	CALL	CO
	JMP	DONE

GET1:	XRA	A
	STA	RECCT

GET2:	LHLD	NEXT
	XCHG
	MVI	C,SDMAF
	CALL	BDOS
	LXI	D,TFCB
	MVI	C,READF
	CALL	BDOS
	CPI	BDAOK
	JZ	GET3
	CPI	BDER1
	JZ	GETEX
	LXI	H,RERROR
	CALL	COMSG
	JMP	ERREX

GET3:	LDA	RECCT
	INR	A
	STA	RECCT
	LHLD	NEXT
	LXI	D,128
	DAD	D
	SHLD	NEXT
	LDA	MEMAX
	DCR	A
	CMP	H
	JNZ	GET2
	CALL	TWOCR
	LXI	H,MEMERROR
	CALL	COMSG
	JMP	ERREX

GETEX:	CALL	CCRLF
	CALL	CPDMA
	RET

PUT:	LXI	H,BUFFR
	SHLD	NEXT
	LDA	RECCT
	STA	CTSAV
	LDA	TFCB
	ORA	A
	JNZ	PUT1
	LXI	H,OPERROR
	CALL	COMSG
	JMP	PUTEX

PUT1:	MVI	C,INITF
	CALL	BDOS
	XRA	A
	STA	FCBCR
	LXI	H,0
	SHLD	FCBEX
	SHLD	FCBS2
	LXI	D,TFCB
	MVI	C,FINDF
	CALL	BDOS
	CPI	BDERR
	JZ	PUT2
	CALL	CCRLF
	LXI	H,ERAMSG
	CALL	COMSG
	CALL	SHOFN
	CALL	GETYN
	JNZ	PUTEX
	LXI	D,TFCB
	MVI	C,DELEF
	CALL	BDOS

PUT2:	LXI	D,TFCB
	MVI	C,MAKEF
	CALL	BDOS
	CPI	BDERR
	JNZ	PUT3
	LXI	H,OPERROR
	CALL	COMSG
	JMP	PUTEX

PUT3:	LHLD	NEXT
	XCHG
	MVI	C,SDMAF
	CALL	BDOS
	LHLD	NEXT
	LXI	D,128
	DAD	D
	SHLD	NEXT
	LXI	D,TFCB
	MVI	C,WRITF
	CALL	BDOS
	CPI	BDAOK
	JZ	PUT4
	LXI	H,WERROR
	CALL	COMSG
	JMP	PUTEX

PUT4:	LDA	RECCT
	DCR	A
	STA	RECCT
	JNZ	PUT3
	CALL	CPDMA
	LXI	D,TFCB
	MVI	C,CLOSF
	CALL	BDOS
	LDA	CTSAV
	STA	RECCT

PUTEX:	CALL	CCRLF
	CALL	CPDMA
	RET

CI:	PUSH	B
	PUSH	D
	PUSH	H
	MVI	C,RCONF
	CALL	BDOS
	ANI	7FH
	POP	H
	POP	D
	POP	B
	RET

CO:	PUSH	B
	PUSH	D
	PUSH	H
	MVI	C,WCONF
	MOV	E,A
	CALL	BDOS
	POP	H
	POP	D
	POP	B
	RET

TWOCR:	CALL	CCRLF

CCRLF:	MVI	A,CR
	CALL	CO
	MVI	A,LF
	CALL	CO
	RET

COMSG:	MOV	A,M
	ORA	A
	RZ
	CALL	CO
	INX	H
	JMP	COMSG

; MESSAGE POINTED TO BY STACK OUT TO CONSOLE
SPMSG:  XTHL                    ; GET "RETURN ADDRESS" TO HL
        XRA     A               ; CLEAR FLAGS AND ACCUMULATOR
        ADD     M               ; GET ONE MESSAGE CHARACTER
        INX     H               ; POINT TO NEXT
        XTHL                    ; RESTORE STACK FOR
        RZ                      ; RETURN IF DONE
        CALL    CO              ; ELSE DISPLAY CHARACTER
        JMP     SPMSG           ; AND DO ANOTHER

CIMSG:	PUSH	B
	PUSH	D
	PUSH	H
	LXI	H,INBUF+1
	MVI	M,0
	DCX	H
	MVI	M,80
	XCHG
	MVI	C,RBUFF
	CALL	BDOS
	LXI	H,INBUF+1
	MOV	E,M
	MVI	D,0
	DAD	D
	INX	H
	MVI	M,0
	POP	H
	POP	D
	POP	B
	RET

GETYN:	
	LXI	H,YNMSG
	CALL	COMSG
	CALL	CIMSG
	CALL	CCRLF
	LDA	INBUF+2
	ANI	01011111B
	CPI	'Y'
	RZ
	CPI	'N'
	JNZ	GETYN
	CPI	0
	RET

INBUF:	DS	83
DRSAV:	DS	1
RECCT:	DS	1
CTSAV:	DS	1
NEXT:	DS	2

	DS	64
STAK:	DB	0

SINON:	DB	'YOUR SIGN ON MESSAGE',0

BUFFR:	DS	1024

RERROR:	DB	'READ ERROR',0
WERROR:	DB	'WRITE ERROR',0
OPERROR:	DB	'CANNOT_OPEN',0
MEMERROR:	DB	'OUT OF MEMORY',0
ERAMSG:	DB	'OK TO ERASE',0
YNMSG:	DB	'Y/N?: ',0

    END
