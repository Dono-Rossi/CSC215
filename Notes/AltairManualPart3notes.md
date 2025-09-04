# Part Three Notes

## A. Front Panel Switches & LEDs
### 1. Switches
* ON–OFF: Powers the machine on/off. Turning off erases memory. 
* STOP–RUN: Halts or starts program execution.
* SINGLE STEP: Executes one machine instruction at a time (each may span multiple cycles).
* EXAMINE / EXAMINE NEXT: Displays contents of the current or next memory location on the data LEDs.
* DEPOSIT / DEPOSIT NEXT: Stores data from the data switches into current or next memory address. Allows entry of new data before deposit.
* RESET / CLR: RESET sets the Program Counter to address 0. CLR clears for external I/O.
* PROTECT / UNPROTECT: Locks or unlocks memory from being changed.
* AUX Switches: Two unused switches reserved for future peripherals.
#### Data/Address switches
	* DATA (bits 7–0)
	* ADDRESS (bits 15–0). For a 256-word system, only bits 0–7 are used.
A switch that is up denotes a 1 bit while a down switch denotes a 0 bit.

### 2. Indicator LEDs
#### Note: When machine is stopped a glowing LED denotes an active status and a non-glowing LED denotes inactive. When running a program LEDs may be erroneus.
* ADDRESS LEDs (A15–A0): Show current memory address.
* DATA LEDs (D7–D0): Show data at that address
* INTE: Interrupt enabled
* PROT: Memory is protected
* WAIT: CPU waiting
* HLDA: Hold acknowledged 

### 3. Status LEDs
#### Note: A glowing LED denotes an active status for the designated condition.
Indicate internal CPU and bus states:
* MEMR: Memory read
* INP: Input data address active
* M1: The CPU is processing the first machine cycle of an instruction
* OUT: Output phase
* HLTA: HALT executed
* STACK: Stack pointer active
* WO: Write operation or output function (vs. read or input)
* INT: Interrupt acknowledged

## B. Loading a Sample Program
A simple addition program in mnemonics: 
0. LDA 
1. MOV A→B 
2. LDA 
3. ADD A+B 
4. STA 
5. JMP

* Converts to binary machine codes, and then to octal for easier input via switches 

#### Steps to load:

1. Use RESET to start at address 0.
2. Enter binary bits via DATA/ADDRESS switches.
3. Use DEPOSIT, then DEPOSIT NEXT for sequential entries.
4. After entering code, deposit the two numbers to add into memory (addresses 128 and 129 by example).
5. Run the program by toggling RESET, then RUN, then halt with STOP.
6. Examine the result at memory 130 using the EXAMINE switch .
Note: You can repeat with different addresses or inputs for practice .

## C. Using Memory
#### Memory mapping is recommended:
* Reserve memory segments for programs, subroutines, and data.
* Example: With 256 words, use the first 100 for code, next 100 for routines, last 56 for data.
* Keep a chart or table to track memory usage and update it when you modify your program.

## D. Memory Addressing
* Direct Adressing: The instruction supplies the specified memory address in the form of two bytes immediately following the actual instruction byte.
* Register Pair Addressing: Uses H and L registers, with H containing the most significant bit and L containing the least signifcant bit, (or B–C, D–E with LDAX/STAX) to hold addresses.
* Stack Pointer Addressing: PUSH/POP (PUSH puts 2 bytes/16 bits and POP retrieves) use the stack (special block of memory reserved by the progreammer); stack location must be set via LXI.
* Immediate Adressing: mmediate instructions contain data which is loaded into memory during program loading, stored in a block reserved by the operator.
* Subroutine (Call/Return): CALL saves the  address of the next instruction of the main program by being pushed onto the stack. RETURN pops it from the stack to resume execution.

## E. Operating Tips
* Proofread Programs: Use RESET and EXAMINE/EXAMINE NEXT to verify each entry; correct mistakes with DEPOSIT.
* Use NOPs: Insert “No Operation” instructions to leave space for future edits; helpful placeholder (e.g., allocate 3 NOPs for potential LDA later).
* Debug via SINGLE STEP: Execute step-by-step, watching status LEDs to spot errors precisely .


