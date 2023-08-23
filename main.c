include "monty.h"

/**
 * main - entry point for the program
 * @argc: the count of arguments
 * @argv: the argument vector
 * Return: on success int
 */
int main(int argc, char **argv)
{
	args = NULL;
	file_name = NULL;
	content = NULL;
	size_t i = 0;
	ssize_t read = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		/*main function loop*/
	}
	fclose(file);
	return (0);
}
