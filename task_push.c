#include "monty.h"

/**
 * op_push - opcode that pushes element to the stack
 * @stack: stack node
 * @line_number: line count
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	int check, i = 0, x = 0;

	if (args != NULL)
	{
		if (args[0] == '-')
			i++;
		while (args[i] != '\0')
		{
			if (args[i] > 57 || args[i] < 48)
				x = 1;
		}
		if (x == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			/*free(content);*/
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		/*extern_free(*stack);*/
		exit(EXIT_FAILURE);
	}
	check = atoi(args);
	if (flag_s == 0)
		st_push(stack, check);
	else
		en_queue(stack, check);
}

/**
 * op_pall - opcode that displays elements in the stack
 * @stack: stack_t node
 * @line_number: file line count
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = *stack;
	(void)line_number;

	while (pointer != NULL)
	{
		printf("%d\n", pointer->n);
		pointer = pointer->next;
	}
}

/**
 * st_push - adds new node to stack
 * @stack: stack_t node
 * @line_number: file line count
 */
void st_push(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = malloc(sizeof(stack_t));

	if (pointer == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}
	if (*stack)
		(*stack)->prev = pointer;
	pointer->n = line_number;
	pointer->next = *stack;
	pointer->prev = NULL;
	*stack = pointer;
}

/**
 * en_queue - adds new node to queue
 * @stack: stack_t node
 * @line_number: node value to add
 */
void en_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *pointer = malloc(sizeof(stack_t));

	if (pointer == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_count);
		exit(EXIT_FAILURE);
	}
	pointer->n = line_number;
	pointer->next = NULL;
	if (*stack)
	{
		while ((*stack)->next)
			*stack = (*stack)->next;
	}
	if (*stack == NULL)
	{
		*stack = pointer;
		pointer->prev = NULL;
	}
	else
	{
		(*stack)->next = pointer;
		pointer->prev = *stack;
	}
}
