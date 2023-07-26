#include "shell.h"

/**
 * _strncpy - Copies at most 'n' characters from the 'src' string to the 'dest' string.
 * @dest: The destination string to be copied to.
 * @src: The source string to be copied from.
 * @n: The maximum number of characters to be copied.
 * Return: A pointer to the destination string 'dest'.
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    while (src[i] != '\0' && i < n - 1)
    {
        dest[i] = src[i];
        i++;
    }

    if (i < n)
    {
        j = i;
        while (j < n)
        {
            dest[j] = '\0';
            j++;
        }
    }
    return s;
}

/**
 * strncat - Concatenates at most 'n' characters from the 'src' string to the end of the 'dest' string.
 * @dest: The first string, and the destination of the concatenation.
 * @src: The second string, and the source of characters to be appended.
 * @n: The maximum number of characters to be appended from 'src'.
 * Return: A pointer to the destination string 'dest'.
 */
char *_strncat(char *dest, char *src, int n)
{
    int i, j;
    char *s = dest;

    i = 0;
    while (dest[i] != '\0')
        i++;

    j = 0;
    while (src[j] != '\0' && j < n)
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    if (j < n)
        dest[i] = '\0';

    return s;
}

/**
 * _strchr - Locates a character 'c' in the string 's'.
 * @s: The string to be parsed.
 * @c: The character to look for.
 * Return: A pointer to the memory area 's' where the character 'c' is found, or NULL if 'c' is not found.
 */
char *_strchr(char *s, char c)
{
    do {
        if (*s == c)
            return s;
    } while (*s++ != '\0');

    return NULL;
}

