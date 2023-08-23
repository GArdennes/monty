0. push, pall
Implement the push and pall opcodes.
The opcode push <int>  pushes an element to the stack. The opcode pall prints all the values on the stack, starting from the top of the stack.
Requirements
If <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE.
You won’t have to deal with overflows. Use the atoi function
For the pall opcode, if the stack is empty, don’t print anything

ALGORITHM
PUSH
Check if there is an argument or if the argument is an integer.
Allocate a new node for the value to be pushed.
Set the new node’s value to the value to be pushed.
Set the new node’s next pointer to the head of the stack.
If the stack is not empty, then set the previous pointer of the new node to the previous node in the stack.
Set the head of the stack to the new node.
PALL
Initialize a pointer to the head of the stack
While the pointer is not NULL
Print the value of the node pointed to by the pointer.
Set the pointer to the next node


1. pint

Implement the pint opcode.
The opcode pint prints the value at the top of the stack, followed by a new line.
Requirements
If the stack is empty, print the error message L<line_number>: can't pint, stack empty followed by a new line, and exit with the status EXIT_FAILURE

ALGORITHM
Initialize a pointer to the head of the stack
if the pointer is not NULL
Print the value of the node pointed to by the pointer.


2. pop
Implement the pop opcode
The opcode pop removes the top element of the stack.
Requirements
If the stack is empty, print the error message L<line_number>: can't pop an empty stack followed by a new line, and exit with the status EXIT_FAILURE

ALGORITHM
Check if the stack is empty. If it is, then the pop operation fails.
Set the variable pointer to the value of the top element of the stack
Set the head of the stack to the next node of the top element
Free the memory allocated to the top element.
Return the value of the top element


3. swap
Implement the swap opcode.
The opcode swap swaps the top two elements of the stack.
Requirements
If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short , followed by a new line, and exit with the status EXIT_FAILURE

ALGORITHM
Check if the stack has at least two elements. If it does not, then the swap fails
Set the nodes top_element_1 and top_element_2 to the values of the top two elements of the stack.
Set the head of the stack to the next node of the top element 2.
Set the next pointer of the top element 1 to the next node of the top element 2.
Set the previous pointer of the top element 2 to the top element 1.
Set the next pointer of the top element 2 to the head of the stack.
Set the previous pointer to the top element 1 to NULL


4. add
Implement the add opcode.
The opcode ‘add’ adds the top two elements of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end, the top element of the stack contains the result and the stack is one element shorter.
Requirements
If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short followed by a new line, and exit with the status EXIT_FAILURE

ALGORITHMS
Check if the stack has at least two elements. If it does not, then the add operation fails.
Take the values of the top two elements of the stack;
Pop the top two elements of the stack.
Push the sum of the two elements onto the stack.


5. nop
Implement the nop opcode.
The opcode nop doesn’t do anything


6. sub
Implement the sub opcode.
The opcode sub subtracts the top element of the stack from the second top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end, the top element of the stack contains the result and the stack is one element shorter.
Requirements
If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short followed by a new line, and exit with the status EXIT_FAILURE

ALGORITHM
Check if the stack has at least two elements. If it does not then the sub operation fails
Take the values of the top two elements of the stack;
Pop the top two elements of the stack.
Push the difference of the two elements onto the stack;


7. div
Implement the div opcode
The opcode div divides the second top element of the stack by the top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end, the top element of the stack contains the result and the stack is one element shorter.
Requirements
If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short followed by a new_line, and exit with the status EXIT_FAILURE
If the top element of the stack is 0, print the error message L<line_number>: division by zero followed by a new line, and exit with the status EXIT_FAILURE

ALGORITHM
Check if the stack has at least two elements. If it does not then the sub operation fails
Check if the top node is a 0 value to avoid division by 0
Take the values of the top two elements of the stack;
Pop the top two elements of the stack.
Push the result of division of the two elements onto the stack


8. Mul
Implement the mul opcode.
The opcode mul multiples the second top element of the stack with the top element of the stack.
The result is stored in the second top element of the stack, and the top element is removed, so that at the end, the top element of the stack contains the result and the stack is one element shorter.
Requirements
If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short followed by a new line, and exit with the status  EXIT_FAILURE

ALGORITHM
Check if the stack has at least two elements. If it does not then the sub operation fails
Take the values of the top two elements of the stack;
Pop the top two elements of the stack.
Push the product of the two elements onto the stack;


9. mod
Implement the mod opcode
The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack. The result is stored in the second top element of the stack, and the top element is removed, so that at the end, the top element of the stack contains the result and the stack is one element shorter.
Requirements
If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short followed by a new line, and exit with the status EXIT_FAILURE
If the top element of the stack is 0, print the error message L<line_number>: division by zero , followed by a new line, and exit with the status EXIT_FAILURE

ALGORITHM
Check if the stack has at least two elements. If it does not then the sub operation fails
Check if the top node is a 0 value to avoid division by 0
Take the values of the top two elements of the stack;
Pop the top two elements of the stack.
Push the result of division of the two elements onto the stack


10. comments
Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).


11. pchar
Implement the pchar opcode
The opcode pchar prints the char at the top of the stack, followed by a new line. The integer stored at the top of the stack is treated as the ascii value of the character to be printed
Requirements
If the value is not in the ascii table(man ascii) print the error message L<line_number>: can't pchar, value out of range followed by a new line, and exit with the status EXIT_FAILURE 
If the stack is empty, print the error message L<line_number>: can't pchar, stack empty followed by a new line, and exit with the status EXIT_FAILURE

ALGORITHM
Check if the stack is empty
Pop the top element of the stack
Convert the top element to a character and print it


12. pstr
Implement the pstr opcode.
The opcode pstr prints the string starting at the top of the stack, followed by a new line. The integer stored in each element of the stack is treated as the ascii value of the character to be printed. The string stops when either, the stack is over or the value of the element is 0 or the value of the element is not in the ascii table
Requirements
If the stack is empty, print only a new line.

ALGORITHM
Check if the stack is empty
Pop the top element of the stack
Convert the top element to a character and print it


13. rotl
Implement the rotl opcode.
The opcode rotl rotates the stack to the top. The top element for the stack becomes the last one, and the second top element of the stack becomes the first one. Rotl never fails


14. rotr
Implement the rotr opcode.
The opcode rotr rotates the stack to the bottom. The last element of the stack becomes the top element of the stack. Rotr never fails.


15. stack, queue
Implement the stack and queue opcodes.
The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program. The opcode queue sets the format of the data to a queue (FIFO). When switching between the two, the top of the stack becomes the front of the queue or the front of the queue becomes the top of the stack


16. Brainf*ck
Write a brainf*ck script that prints School, followed by a new line.
All your Brainf*ck files should be stored inside the bf sub directory. You can install the bf interpreter to test your code: sudo apt-get install bf


17. Add two digits
Adds two digits given by the user. Read the two digits from stdin, add them, and print the result using brainf*ck script. The total of the two digits will be one digit-long(<10)


18. Multiplication
Write a brainf*ck script that multiplies two digits given by the user. Read the two digits from stdin, multiply them, and print the result. The result of the multiplication will be one digit-long(<10)


19. Multiplication level up
Write a brainf*ck script that multiplies two digits given by the user. Read the two digits from stdin, multiply them, and print the result, followed by a new line.

