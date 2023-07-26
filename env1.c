#include "shell.h"

/**
 * _myenv - Prints the current environment.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - Gets the value of an environment variable.
 * @info: Structure containing potential arguments.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable if found, otherwise NULL.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = _starts_with(node->st, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initializes a new envirnment var or modifies an existing one.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int _mysetenv(info_t *info)
{
	if (info->agc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (_setenv(info->environ, info->agv[1], info->agv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Removes an environment variable.
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0.
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->agc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (i = 1; i < info->agc; i++)
		_unsetenv(&info->environ, info->agv[i]);

	return (0);
}

/**
 * poplate_env_list - Populates the environment linked list.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int poplate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
