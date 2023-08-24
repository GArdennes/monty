#include "monty.h"

/**
 * main - entry point of program
 * @argc: argument count
 * @argv: argument vector
 * Return: On success int
 */
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		file_name = fopen(argv[1], "r");
		if (file_name == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty(argv);

	return (0);
}

/**
 * monty - main monty program
 * @argv: argument vector
 * Return: On success int
 */
int monty(char **argv)
{
	ssize_t r = 0;
	int check = 0, i;
	char *input = NULL;
	stack_t *stack = NULL;
	(void)argv;

	extern_clear();
	while (r != -1)
	{
		r = get_input();
		if (r != -1)
		{
			input = input_buf();
			check = execute_cmds(&stack, input);
			if (check == -1)
			{
				i = line_count;
				fprintf(stderr, "L%d: unknown instruction %s\n", i, input);
				extern_free(stack);
				exit(EXIT_FAILURE);
			}
		}
		extern_free(NULL);
	}
	extern_free(stack);

	return (0);
}
