#include "monty.h"

/**
 * _strdup - function that duplicates a string
 * @s: string
 * Return: On success char *
 */
char *_strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	char *dup = malloc(len);

	if (dup != NULL)
		memcpy(dup, s, len);
	return (dup);
}
