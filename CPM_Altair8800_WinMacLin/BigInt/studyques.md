# Questions and Answers

## Page 3

### 1. Suppose you want to add unary operations (i.e., ones requiring only one operand) to the calculator. For example, we might add "M" to indicate unary minus (i.e., change the sign of the old value) and "A" to indicate absolute value. What changes would need to be made to the program?
To support the new operations, the program must:
- Change the command-pocessing or if/else system to recognize new operators.
- Ensure the parser does not ask for another number when the unary operator is used.
- Add new symbols to the input command.
- Apply the unary operator to the current value, with no prompt for another operand.
### 2. Suppose that words rather than single character symbols are to be used for the operators (e.g., the user types "times" instead of "*"). Where in the program would the necessary changes occur?
Changes would occur in:
- The input parsing section, where operators are read.
- Replacing `char` input for operators with `string` input.
- Updating comparisons in the command-processing logic (e.g., `"times"` instead of `'*'`).
- Possibly adjusting tokenization logic if input is read as a stream.
### 3. Suppose that the calculator is to be converted to use C++ double values rather than integers. Where would changes need to be made?
Required changes:
- Replace all `int` variables storing values with `double`.
- Update function parameter and return types.
- Adjust arithmetic operations to account for floating-point behavior.
- Modify input/output formatting for decimal values.
- Review error handling for floating-point edge cases (NaN and infinity).
### 4. Most modern systems support graphical displays and mouse (or other pointer) input. Rewrite the Calculator program to take advantage of these features to produce an on-screen push-button calculator (this is a large programming project).
Rewrite steps:
- Replace text-based input with a GUI framework.
- Maintain internal state for the current value and pendin goperations.
- Update the display after each interaction.
- Create buttons for digits and operations.
- Use even-driven programming for button clicks.
### 5. Show how a new command, "C", which acts like the "Clear" command on a calculator could be implemented. The clear command sets the current value to zero.
Implementation steps:
- Add 'C' as a recognized command.
- Do not request additional operands.
Ensure the display or output reflects the reset value.
- In the command-processing logic, set the current value to zero.
### 6. (AB only) How could the calculator be modified to allow the use of parentheses to control the order of operations?
Required Changes:
- Store operators and operands seperately
- Evaluate expressions based on precendence and parantheses.
- Replace the left-to-ride evaluation model.`
- replace the LHS and RHS models.
- Store operators and operands seperately.
## Page 6

### 1. What are the largest and smallest integer values in the programming environment you use?
Maximum: 2,147,483,647
Minimum: -2,147,483,648
### 2. Each BigInt object will need to store the digits that represent the BigInt value. The decision to allow arbitrarily large BigInt values affects the choices for storing digits. Name one method for storing digits that will permit an arbitrary number of digits to be stored. What effect would a limit on the number of digits in a BigInt have in the design of the BigInt class?
Method: Storing through arrays
- Assign each digit in a character to an array, storing more digits.
- Limited number of digits would affect how the arrays are used.
- Shorter arrays would make the class more comploicated but faster to run.
### 3. Based on your knowledge of pencil-and-paper methods for doing arithmetic, what do you think will be the most difficult arithmetic operation (+, *, -) to implement for the BigInt class? Why?
Multiplication is the most difficult as:
- It requires carrying across many digits.
- Complexity increases as numbers grow, so does time.
- Similar to factorials with repeated multiplication.
### 4. Experiment with the calculator. If you enter abcd1234 when a number is expected, what happens? If you enter 1234abcd is the behavior different? What happens if you enter an operator that’s not one of the three that are implemented
?
- Input `abcd1234`: conversion fails immediately when a number is expected.
- Input `1234abcd`: the numeric portion is read first, then the stream fails.
- Invalid operator input: the program either rejects it or ignores it, depending on implementation.
### 5. List as many operations as you can that are performed on integers, but that are not included in the list of BigInt functions and operators above.
- Bitwise operations
- Modulo
- Bit shifting
- Exponentiation
- Increment and decrement
- Division with remainder
- Logical operations
### 6. (AB only) What implementation decisions would require providing a destructor, a copy constructor, and an assignment operator?
- The class manages dynamic memory.
- Resources must be released explicitly.
- Deep copies are required.
- Assignment must avoid memory leaks or double deletion.
### 7. Consider the headers for operator- and operator+ given below.
BigInt operator - (const BigInt & big, int small);
// postcondition: returns big - small
BigInt operator + (const BigInt & big, int small);
// postcondition: returns big + small
### Write the body of operator- assuming that operator+ has been written.
- Needs to delcare a pointer for the large and small numbers
- individually subtract digits from respective significances.
- Start large to small
- Add all the negatives together. 
 
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
