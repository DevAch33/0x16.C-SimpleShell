#include "shell.h"

/**
 * _memset - fill memory with a constant byte.
 * @st: Pointer of the memory area
 * @c: Value to be filled.
 * @n: Number of bytes to be set to the value.
 *
 * Return: pointer to the memory area st.
 */
char *_memset(char *s, char c, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		st[i] = c;
	return (st);
}
