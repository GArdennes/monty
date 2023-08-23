#include "monty.h"

/**
 * op_div - opcode that carries out division of the top two elements
 * @stack: stack_t node
 * @line_number: file line count
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;
	int buffer, len;

	if (pointer == NULL)
		exit(EXIT_FAILURE);
	for (len = 0; pointer != NULL; len++)
		pointer = pointer->next;

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	pointer = *stack;
	if (pointer->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	buffer = pointer->next->n / pointer->n;
	pointer->next->n = buffer;
	*stack = pointer->next;
	free(pointer);
}
