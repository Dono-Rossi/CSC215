# Chapter 13: Buffered Input/Output
by Noah and Donavan
10/30/2025

### Chapter Goal
"To enter, assemble, and test subroutines that will transfer a line at a time beteen programs and the computer operator."
## Introduction
This chapter will introduce the concept of "Buffered Input/Output" in CP/M assembly programming. It talks about how to use buffers to manage data flow efficiently

## What is Buffered I/O
- __Buffered I/O__ uses memory buffers to hold data temporarily while input and output operations are happening
- This is useful because it helps to regulate differences in speed between the parts of the system that work together like the CPU and I/O devices.

### Input Buffering
- The input devices send data to the assembler which stores it in a buffer untill the CPU is prepared to process it
- This prevents data loss in the case that the input data is transmited faster than the CPU is ready for.
	- The __ISR__ or interrupt service routine stores the incoming data in the buffer

### Output Buffering
- Data being sent to output devices is stored in a buffer first
- This allows the CPU to continue to process the data while device processes output

## Buffers
- There are some things to consider when creating a buffer
1. if the buffer is too small, data overflows can happen and data can be lost
2. if the buffer is too large, there is wasted memory space
- __Circular Buffers__ are buffers that, when full, wrap around and start overwriting data from the beggining that has already been processed
- This allows for continous use and reduces the need to be perfect about buffer size

## Debugging, DDT
- First step is to load DDT and your program, removing all disks from the drives
- Used to step through and trace code 
- Allows you can see registers, memory and the console behavior while testing routines.
- Workflow:
    - Load DDT with DDT CPMIO.COM which places it into the TPA, setting up vectors
    - However, the TPA can only be used by one .COM file (CPMIO or DDT), so it then relocats itself to the memory, overlaying CCP
    - Establishes location for itself in 38H
- More Debugging
    - 38H is an interrupt vector
    - Uses this for breakpointing program during tests
    - At breakpoints, DDT plugs 0FFH into the program
    - This causes a software interrupt, as DDT saves and displays the contents of CPU registers
- Lets you set breakpoints, single‑step or trace execution, examine/modify registers and memory, dump memory contents, and intercept BDOS calls.
