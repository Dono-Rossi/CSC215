# CP/M Chapter 8 Notes
# By Donovan and Noah

## The Evolution of the 8080
"Version 2 (of anything) is the first version that actually works"
- In the 8080 we have 244 commands avalibe to the programmer out of the 256 possible. 
- The 12 that are not avalible to the programmer are pre programmed into the machine. 
- The microprocessors involved in the altair 8080 and the 8085 have a few key differences that affect the performance of the machine the chips were found in
1. One of the most important evolutions of the microprosessor is its power supply. 
	- The 8080 required three different voltages, making the machine expensive and complex while the 8085 one required one, simplifying and reducing costs
2. The 8085 also has two new opcodes, a one bit input and a one bit output and four hardware interrupt inputs that require interrupt vectors to be added to low memory if they are used. 
3. The 8085 also executes commands faster than the 8080

## The Zilog Z80
- In the 8080, there were 12 unused opcodes
- the 8085 filled 2 of them
- the Z80, another descendent of the 8080, uses all 12
- This increases uses but can also get complicated when people try to move back and forth between the individual microprocessors
- The easiest solution is just to use the instructions on the origional 8080 set, which in standard throughout all versions
 
## THE TWELVE
* Out of 256 possible cominations of eight binary bits, the 8080 used 244 of them, leaving TWELVE bit patterns unused
* In the 8085, TWO of these TWELVE combinations are used, 20H and 30H
* In the Z80, ALL of these TWELVE combinations are used, except the ones in the 8085 are for different functions 
    * Used these TWELVE opcodes for more than TWELVE instructions
    * Used a one-byte opcode to tell the CPU to fetch the next byte in memory, and decode that as a new instruction
    * Acted as windows into a whole instruction set
* This method of the Z80, uses more memory space and time, but provides very powerful instructions

## The National Semiconductor NSC800
* The designers of the National NSC800 had it easy
    * Examined other's products and built off of them
    * Little personal innovation
* Borrowed IC pinouts from the 8085
* Borrowed the super instruction set from the Z80
* NSC 800 os a CMOS integrated circuit
    * Can run using a fraction of the power its predecessors needed (at a higher price)
* In conclusion, the NSC800 is a versatile and efficient tool, that contains the best of both worlds between the 8085 and Z80

## Establishing a Common Ground
### Relatives
* 8085
    * Good for controllers that operate at high speeds in real time
* Z80
    * For program-intensive applications (ex. high level language compiler)
    * Instruction set significantly reduces programmer effort
* 8080
    * Program can run on any CP/M computer
    * Allow you to sell millions of copies and make beaucoup bucks
### Rest of the book
* If you truly want portability, your program needs to be able to be assembled in the CP/M assembler.
    * Assemblers for 8085 and Z80 and other micros can run on CP/M, but reduce portability, and will be ignoreed for the rest of the book
#### Instructions
* Two conditional jumps that test parity of accumulator contents
    * JPE (Jump Parity Even): Transfer of program execution the specified address if accumulator contains an even number of one bits following an operation with the ALU (arithmetic/logic unit) 
    * JPO (Jump Parity Odd): Same as previous but if odd 

The JPE and JPO work in the Z80 only if the preceding ALU operation was logical: AND, OR, ZOR. However, the flag bit that record parity in the 8080 indicated operation overflow in the Z80.
* Leads to 8080 programs that bomb on the Z80
* BOMBED MICROSOFT BASIC :O

## Avoiding Conflicts
- On Z80, there are commands that just don't work on the CP/M assembler
- Becasue of this, many conflicts arise when the Z80 clashes with CPM
- To solve this, the 8080 provides 'absolute adressing' where Jump instructions go to a definite location in memory
- the Z80 adds 'relative adressing' where a jump can be specified to a location

