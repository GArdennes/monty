#include "monty.h"

/**
 * op_pint - opcode that prints value at the top of the stack
 * @stack: stack_t node
 * @line_number: file line_number
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;

	if (pointer == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", pointer->n);
}
