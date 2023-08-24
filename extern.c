#include "monty.h"

/**
 * extern_clear - function to clear extern
 */
void extern_clear(void)
{
	content = NULL;
	file_name = NULL;
	args = NULL;
	line_count = 0;
	flag_s = 0;
}

/**
 * extern_free - function to free extern
 * @stack: stack_t node
 */
void extern_free(stack_t *stack)
{
	fclose(file_name);
	free(content);
	free(args);

	if (stack)
		free_stack(stack);
}

/**
 * free_stack - function to free stack
 * @stack: stack_t node
 */
void free_stack(stack_t *stack)
{
	stack_t *node = NULL;

	while (stack != NULL)
	{
		node = (stack)->next;
		free(stack);
		(stack) = node;
	}
}

/**
 * extern_set - initializes extern variables
 */
void extern_set(void)
{
	content = malloc(sizeof(char) * 1024);
	args = malloc(sizeof(char) * 1024);
}
