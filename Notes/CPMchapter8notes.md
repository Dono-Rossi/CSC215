# CP/M Chapter 8 Notes

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
    * JPE (Jump Parity Even): Transfer of program execution the specified address if accumulator contains an even number of one bits following an operation with the ALU 
    * JPO (Jump Parity Odd): Same as previous but if odd 

The JPE and JPO work in the Z80 only if the preceding ALU operation was logical: AND, OR, ZOR. However, the flag bit that record parity in the 8080 indicated operation overflow in the Z80.
* Leads to 8080 programs that bomb on the Z80

