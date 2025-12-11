; ascii
cr	equ	0dh
lf	equ	0ah
ctrlz	equ	1ah

; bdos functions
rconf	equ	1
wconf	equ	2
rbuff	equ	10

rboot	equ	0
bdos	equ	5
tpa	equ	100h

	org	tpa

start:	lxi	sp,stak
start1:	lxi	h,inbuf
	call	cimsg
	call	ccrlf
	mvi	b,1
start2:	mov	a,m
	inx	h
	ora	a
	jz	start3
	inr	b
	jmp	start2
start3:	mov	a,b
	call	conum
	ret


CO:	PUSH	B 
PUSH	D
PUSH    H
MVI       C, WCONF 
MOV      E,A
CALL     BDOS
POP        H 
POP        D
POP         B
RET


CI:	PUSH      B
	PUSH      D
	PUSH      H
	MVI	    C,WCONF
	MOV	    E, A
	CALL     BDOS
	POP        H
	POP        D	
	POP        B
	RET

comsg:	MSG:    DB 'Character count: $'
push	a
	push	h
	mov	a,m
	ora	a
	jz	comsg1
	call	co
	inx	h
	jmp	comsg
comsg1:	pop	h
	pop	a
	ret

cimsg:	PROMPT: DB 'Enter text: $'
push	a
	push	b
	push	d
	push	h
	dcx	h
	push	h
	dcx	h
	xchg
	mvi	c,rbuff
	call	bdos
	pop	h
	mov	e,m
	mvi	d,0
	dad	d
	inx	h
	mvi	m,0
	pop	h
	pop	d
	pop	b
	pop	a
	ret
INBUF:    DS      83

conum:	push	a
	push	b
	push	d
	push	h
	mvi	b,0
conum1:	sui	100
	jc	conum2
	inr	b
	jmp	conum1
conum2:	adi	100
	push	a
	mov	a,b
	mov	c,b
	ora	a
	jz	conum3
	adi	'0'
	call	co
conum3:	pop	a
	mvi	b,0
conum4:	sui	10
	jc	conum5
	inr	b
	jmp	conum4
conum5:	adi	10
	push	a
	mov	a,b
	ora	c
	jz	conum6
	mov	a,b
	adi	'0'
	call	co
conum6:	pop	a
	adi	'0'
	call	co
	pop	h
	pop	d
	pop	b
	pop	a
	ret
