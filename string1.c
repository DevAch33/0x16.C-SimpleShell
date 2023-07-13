#include "shell.h"

/**
 * _strlen - It returns the string's length
 * @st: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *st)
{
	int i = 0;

	if (!st)
		return (0);

	while (*st++)
		i++;
	return (i);
}
