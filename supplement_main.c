#include "monty.h"

/**
 * get_input - function that gets file content
 * Return: On success ssize_t
 */
int get_input(void)
{
	size_t buf = 0;
	char *read = NULL;
	ssize_t i;

	read = fgets(content, buf, file_name);
	if (read != NULL)
		i = 0;
	else
		i = -1;
	line_count++;

	return (i);
}

/**
 * input_buf - function that gets commands
 * Return: On success char *
 */
char *input_buf(void)
{
	char *sift;
	char *content_copy = _strdup(content);

	sift = strtok(content_copy, " \n\t");
	if (sift && strcmp(sift, "#") == 0)
	{
		free(content_copy);
		return (NULL);
	}
	args = strtok(NULL, " \n\t");
	free(content_copy);
	return (sift);
}

/**
 * execute_cmds - function that finds opcode
 * @stack: stack_t node
 * @input: input command
 * Return: on success int
 */
int execute_cmds(stack_t **stack, char *input)
{
	int i, opcode_in = -1;
	instruction_t op_built[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pop", op_pop},
		{"nop", op_nop},
		{"swap", op_swap},
		{"sub", op_sub},
		{"add", op_add},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{NULL, NULL}
	};

	for (i = 0; op_built[i].opcode && input; i++)
	{
		if (strcmp(input, op_built[i].opcode) == 0)
		{
			opcode_in = 0;
			(*op_built[i].f)(stack, line_count);
			break;
		}
	}
	return (opcode_in);
}
