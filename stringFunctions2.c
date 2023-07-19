#include "shell.h"

/**
* _puts - prints an input string
* @st: the string to be printed
*
* Return: Nothing
*/
void _puts(char *st)
{
	int i = 0;

	if (!st)
		return;
	while (st[i] != '\0')
	{
		_putchar(st[i]);
		i++;
	}
}

/**
* _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
* **strtow - splits a string into words. Repeat delimiters are ignored
* @st: the input string
* @d: the delimeter string
* Return: a pointer to an array of strings, or NULL on failure
*/

char **strtow(char *st, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (st == NULL || st[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; st[i] != '\0'; i++)
		if (!is_delim(st[i], d) && (is_delim(st[i + 1], d) || !st[i + 1]))
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(st[i], d))
			i++;
		k = 0;
		while (!is_delim(st[i + k], d) && st[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = st[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
