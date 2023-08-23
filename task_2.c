#include "monty.h"

/**
 * op_pop - opcode that removes top element of stack
 * @stack: stack_t node
 * @line_number: file line count
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;

	if (pointer == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = pointer->next;
	if (*stack != NULL)
		*stack->prev = NULL;
	free(pointer);
}
