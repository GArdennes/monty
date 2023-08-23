#include "monty.h"

/**
 * op_swap - opcode that swaps the top two elements of the stack
 * @stack: stack_t node
 * @line_number: file line count
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;
	int buffer = 0;

	if (pointer == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	buffer = pointer->n;
	pointer->n = pointer->next->n;
	pointer->next->n = buffer;
}
