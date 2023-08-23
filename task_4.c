#include "monty.h"

/**
 * op_add - opcode that adds tow top elements of the stack
 * @stack: stack_t node
 * @line_number: file line count
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;
	int buffer, len;

	if (pointer == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (len = 0; pointer != NULL; len++)
		pointer = pointer->next;

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	pointer = *stack;
	buffer = pointer->n + pointer->next->n;
	pointer->next->n = buffer;

	*stack = pointer->next;
	free(pointer);
}
