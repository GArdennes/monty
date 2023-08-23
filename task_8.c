#include "monty.h"

/**
 * op_mul - opcode that multiples the top two elements
 * @stack: stack_t node
 * @line_number: file line number
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;
	int buffer, len;

	if (pointer == NULL)
		exit(EXIT_FAILURE);
	for (len = 0; pointer != NULL; len++)
		pointer = pointer->next;

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	pointer = *stack;
	buffer = pointer->next->n * pointer->n;
	pointer->next->n = buffer;
	*stack = pointer->next;

	free(pointer);
}
