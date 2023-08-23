#include "monty.h"

/**
 * op_pchar - opcode that prints the char at that top of the stack
 * @stack: stack_t node
 * @line_number: file line count
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;

	if (pointer == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	if (pointer->n > 127 || pointer->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", pointer->n);
}
