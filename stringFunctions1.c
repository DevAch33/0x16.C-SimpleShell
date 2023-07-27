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

/**
 * _strcmp - It compares two strings and returns 0 if the strings are the same.
 * @st1: string 1
 * @st2: string 2
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *st1, char *st2)
{
	while (*st1 && *st2)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	if (*st1 == *st2)
		return (0);
	else
		return (*st1 < *st2 ? -1 : 1);
}

/**
 * _strcat - It concatenates two strings and returns the concatenated string.
 * @dest: The destination string
 * @src: the source string
 *
 * Return: This function returns a pointer to the resulting string dest.
 */
char *_strcat(char *dest, const char *src)
{
	char *r = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (r);
}

/**
 * _strcpy - It copies one string into another.
 * @dest: Pointer to the destination array where the content is to be copied
 * @src: String to be copied.
 *
 * Return: This returns a pointer to the destination string dest.
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - functions are used to duplicate a string.
 * @st: String to duplicated
 *
 * Return: Pointer to null-terminated byte string.
 */
char *_strdup(const char *st)
{
	int length = 0;
	char *r;

	if (st == NULL)
		return (NULL);
	while (*st++)
		length++;
	r = malloc(sizeof(char) * (length + 1));
	if (!r)
		return (NULL);
	for (length++; length--;)
		r[length] = *--st;
	return (r);
}
/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
