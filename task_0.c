#include "monty.h"

/**
 * op_push - opcode that pushes element to the stack
 * @stack: stack node
 * @line_number: line count
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = malloc(sizeof(stack_t));

	if (pointer == NULL)
		exit(EXIT_FAILURE);

	pointer->n = args;
	pointer->next = *stack;
	pointer->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = pointer;
	*stack = pointer;
}

/**
 * op_pall - opcode that displays elements in the stack
 * @stack: stack_t node
 * @line_number: file line count
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;

	while (pointer != NULL)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->next;
	}
}
