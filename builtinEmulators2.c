#include "shell.h"

/**
 * unset_alias - Unsets an alias by removing it from the alias list.
 * @info: Pointer to the structure containing potential arguments.
 * @st: The string containing the alias to unset.
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *st)
{
	char *p, c;
	int ret;

	p = strchr(st, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, st, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - Sets an alias by adding it to the alias list.
 * @info: Pointer to the structure containing potential arguments.
 * @st: The string containing the alias to set.
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *st)
{
	char *p;

	p = strchr(st, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, st));

	unset_alias(info, st);
	return (add_node_end(&(info->alias), st, 0) == NULL);
}

/**
 * print_alias - Prints an alias string.
 * @node: The alias node to print.
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = strchr(node->st, '=');
		for (a = node->st; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
