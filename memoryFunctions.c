#include "shell.h"

/**
 * _memset - fill memory with a constant byte.
 * @st: Pointer of the memory area
 * @c: Value to be filled.
 * @n: Number of bytes to be set to the value.
 *
 * Return: pointer to the memory area st.
 */
char *_memset(char *st, char c, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		st[i] = c;
	return (st);
}

/**
 * _realloc - allocate and free dynamic memory.
 * @pnt: Pointer to previous allocated block.
 * @old_s: Byte size of previous block.
 * @new_s: Byte size of previous block.
 *
 * Return: Pointer to the reallocated memory block.
 */
void *_realloc(void *pnt, unsigned int old_s, unsigned int new_s)
{
	char *p;

	if (!pnt)
		return (malloc(new_s));
	if (!new_s)
		return (free(pnt), NULL);
	if (new_s == old_s)
		return (pnt);

	p = malloc(new_s);
	if (!p)
		return (NULL);

	old_s = old_s < new_s ? old_s : new_s;

	while (old_s--)
		p[old_s] = ((char *)pnt)[old_s];
	free(pnt);
	return (p);
}

/**
* ffree - frees a string of strings
* @ss: string of strings
*/
void ffree(char **ss)
{
	char **a = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(a);
}

/**
* bfree - frees a pointer and NULLs the address
* @apf: address of the pointer to free
*
* Return: 1 if freed, otherwise 0.
*/
int bfree(void **apf)
{
	if (apf && *apf)
	{
		free(*apf);
		*apf = NULL;
		return (1);
	}
	return (0);
}

