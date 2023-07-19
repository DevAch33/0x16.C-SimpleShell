#include "shell.h"

/**
* clear_info - initializes info_t struct
* @info: struct address
*
* Return: This function doesn’t return any value.
*/
void clear_info(info_t *info)
{
	info->ag = NULL;
	info->agv = NULL;
	info->path = NULL;
	info->agc = 0;
}

/**
* set_info - initializes info_t struct
* @info: struct address
* @av: argument vector
*
* Return: This function doesn’t return any value.
*/
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->ag)
	{info->agv = strtow(info->ag, " \t");
		if (!info->agv)
		{info->agv = malloc(sizeof(char *) * 2);
			if (info->agv)
			{
				info->agv[0] = _strdup(info->ag);
				info->agv[1] = NULL;
			}
		}
		for (i = 0; info->agv && info->agv[i]; i++)
			;
		info->agc = i;
		replace_alias(info);
		replace_vars(info);
	}
}

/**
* free_info - frees info_t struct fields
* @info: struct address
* @all: true if freeing all fields
*
* Return: This function doesn’t return any value.
*/
void free_info(info_t *info, int all)
{
	ffree(info->agv);
	info->agv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->ag);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
		info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
