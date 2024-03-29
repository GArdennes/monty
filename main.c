#include "monty.h"

/**
 * main - entry point of program
 * @argc: argument count
 * @argv: argument vector
 * Return: On success int
 */
int main(int argc, char **argv)
{
	extern_clear();
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
	int r = 0;
	int check = 0, i;
	char *input = malloc(sizeof(char) * 1024);
	stack_t *stack = NULL;
	(void)argv;

	if (input == NULL)
		exit(EXIT_FAILURE);

	extern_set();
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
				free(stack);
				fclose(file_name);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(stack);
	free(input);
	extern_free(NULL);

	return (0);
}
