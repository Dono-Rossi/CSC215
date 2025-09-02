# Set One

## Introduction

- The Altair 8800 emerged due to breakthroughs in semiconductor tech. It was a highly affordable microcomputer built around Intel’s Model 8080 CPU on a single chip.

- It leveraged N-channel LSI MOS (metal-oxide-semiconductor) technology, marking a milestone in computing.

- This manual aims to serve both novices (with electronics experience) and experienced programmers (with limited electronics background). It introduces logic, number systems, and basic programming—preparing us for more advanced parts.

## Part A
	George Boole, a ninteenth century British mathematician, made a detailed study of the relationship between certain fundamental logical expressions and their arithmetic counterparts, publishing “The Mathematical Analysis of Logic”, 1847; expanded 1854.
	Boole’s system of logic, which is frequently called Boolean algebra, assumes that a logic condition or statement is either true or false. It cannot be both true and false, and it cannot be partially true or partially false. This works perfectly with computers which has a switch that can either be on or off (1/0).
	-  Boolean logic uses binary values—true/false or ON/OFF, often represented as 1/0—perfectly suited to electronic circuits.
Basic logic operations:
	- AND: output is true only if both inputs are true.
	- OR: output is true if any input is true.
	- NOT: inverts the input (true becomes false, vice versa).


## Part B
- The boolean functions (AND, OR, NOT) are physically realized using transistor circuits, often depicted via standardized logic gate symbols.
- There are also two combined logic gates:
	- NAND (NOT-AND)
	- NOR (NOT-OR)
	- Exclusive-OR (XOR) gate, which outputs true only if inputs differ—useful in binary addition (sum and carry logic)
- Flip-flops (built with NAND circuits) act as flip-flops—basic memory elements that toggle state on pulses. Cascading flip-flops, monostable, and astable circuits enable counters, registers, timers, and oscillators.
## Part C
While humans favor decimal (base-10), computers operate in binary. Other bases like octal (base-8) and hexadecimal (base-16) offer efficient shorthand for long binary strings.

## Part D

- Computers—including the Altair—use binary (base-2) for operations. A typical binary word (often 8 bits) would appear as: 10111010. 
- Binary may seem intimidating, but it’s simpler than decimal due to only two symbols (0 and 1). 

When you have a binary number, starting form the right, you multiply the placeholder (either 1 or 0) by 2 to the power of its relative position. The far right's number starts at 0. 
	- Example: 10011₂ = (1×2⁴) + (0×2³) + (0×2²) + (1×2¹) + (1×2⁰) = 16 + 0 + 0 + 2 + 1 = 19.


