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
## C. Using Memory

## D. Memory Addressing

## E. Operating Tips

