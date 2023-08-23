#include "monty.h"

/**
 * op_pstr - opcode that prints the string starting at the top
 * @stack: stack_t node
 * @line_number: file line count
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;
	(void)line_number;

	while (pointer != NULL)
	{
		if (pointer->n > 127 || pointer->n < 0)
			break;
		printf("%c", pointer->n);
		pointer = pointer->next;
	}
	printf("\n");
}
