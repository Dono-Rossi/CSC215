# Questions and Answers

## Page 3

### 1. Suppose you want to add unary operations (i.e., ones requiring only one operand) to the calculator. For example, we might add "M" to indicate unary minus (i.e., change the sign of the old value) and "A" to indicate absolute value. What changes would need to be made to the program?
To support the new operations, the program must:
- Change the command-pocessing or if/else system to recognize new operators.
- Ensure the parser does not ask for another number when the unary operator is used.
- Add new symbols to the input command.
- Apply the unary operator to the current value, with no prompt for another operand.
### 2. Suppose that words rather than single character symbols are to be used for the operators (e.g., the user types "times" instead of "*"). Where in the program would the necessary changes occur?

### 3. Suppose that the calculator is to be converted to use C++ double values rather than integers. Where would changes need to be made?

### 4. Most modern systems support graphical displays and mouse (or other pointer) input. Rewrite the Calculator program to take advantage of these features to produce an on-screen push-button calculator (this is a large programming project).

### 5. Show how a new command, "C", which acts like the "Clear" command on a calculator could be implemented. The clear command sets the current value to zero.

### 6. (AB only) How could the calculator be modified to allow the use of parentheses to control the order of operations?

## Page 6

### 1. What are the largest and smallest integer values in the programming environment you use?

### 2. Each BigInt object will need to store the digits that represent the BigInt value. The decision to allow arbitrarily large BigInt values affects the choices for storing digits. Name one method for storing digits that will permit an arbitrary number of digits to be stored. What effect would a limit on the number of digits in a BigInt have in the design of the BigInt class?

### 3. Based on your knowledge of pencil-and-paper methods for doing arithmetic, what do you think will be the most difficult arithmetic operation (+, *, -) to implement for the BigInt class? Why?

### 4. Experiment with the calculator. If you enter abcd1234 when a number is expected, what happens? If you enter 1234abcd is the behavior different? What happens if you enter an operator that’s not one of the three that are implemented
?
### 5. List as many operations as you can that are performed on integers, but that are not included in the list of BigInt functions and operators above.

### 6. (AB only) What implementation decisions would require providing a destructor, a copy constructor, and an assignment operator?

### 7. Consider the headers for operator- and operator+ given below.
BigInt operator - (const BigInt & big, int small);
// postcondition: returns big - small
BigInt operator + (const BigInt & big, int small);
// postcondition: returns big + small
### Write the body of operator- assuming that operator+ has been written. 
 
## Page 10

### 1. C++ error handling behavior

### 2. BigInt error enum

### 3. Turning Off Error Checking

### 4. Interactive Error-Handling Approach
#### Strengths:
#### Weaknesses:

### 5. Global Variable for Error Results
#### Strengths:
#### Weaknesses:

## PAge 17

### 1. Why is a char vector used to store digits instead of an int vector? How does this affect implementation?

### 2. Alternatives to using an enum for the sign of a BigInt

### 3. Write the GetDigit function and discuss possible errors

#### 4. Why are `operator==` and `operator<` difficult to write? Write `operator==` for positive BigInts

#### 5. Why is `apvector` better than built-in arrays for BigInt?
