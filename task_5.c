#include "monty.h"

/**
 * op_nop - opcode that does nothing
 * @stack: stack_t node
 * @line_number: file line count
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
