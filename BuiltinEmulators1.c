#include "shell.h"

/**
 * my_exit - Exits the shell
 * @info: Pointer to the structure containing potential arguments. Used to maintain
 *         constant function prototype.
 *
 * Return: Exits with a given exit status (0) if info->agv[1] != "exit"
 */
int my_exit(info_t *info)
{
	int exit_code;

	if (info->agv[1])  /* If there is an exit argument */
	{
		exit_code = str_to_int(info->agv[1]);
		if (exit_code == -1)
		{
			info->status = 2;
			_eputs("Illegal number: ");
			_eputs(info->agv[1]);
			_eputchar('\n');
			return 1;
		}
		info->err_num = str_to_int(info->agv[1]);
		return -2;
	}
	info->err_num = -1;
	return -2;
}

/**
 * my_cd - Changes the current directory of the process
 * @info: Pointer to the structure containing potential arguments. Used to maintain
 *         constant function prototype.
 *
 * Return: Always 0
 */
int my_cd(info_t *info)
{
	char *current_dir, *new_dir, buffer[1024];
	int chdir_ret;

	current_dir = getcwd(buffer, 1024);
	if (!current_dir)
		_eputs("TODO: >>getcwd failure emsg here<<\n");

	if (!info->agv[1])
	{
		new_dir = _getenv(info, "HOME=");
		if (!new_dir)
			chdir_ret = /* TODO: What should this be? */
				chdir((new_dir = _getenv(info, "PWD=")) ? new_dir : "/");
		else
			chdir_ret = chdir(new_dir);
	}
	else if (_strcmp(info->agv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_eputs(current_dir);
			_eputchar('\n');
			return 1;
		}
		_eputs(_getenv(info, "OLDPWD="));
		_eputchar('\n');
		chdir_ret = /* TODO: What should this be? */
			chdir((new_dir = _getenv(info, "OLDPWD=")) ? new_dir : "/");
	}
	else
		chdir_ret = chdir(info->agv[1]);

	if (chdir_ret == -1)
	{
		_eputs("can't cd to ");
		_eputs(info->agv[1]);
		_eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return 0;
}

/**
 * my_help - Displays help information
 * @info: Pointer to the structure containing potential arguments. Used to maintain
 *         constant function prototype.
 *
 * Return: Always 0
 */
int my_help(info_t *info)
{
	char **arg_array;

	arg_array = info->agv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* Temp att_unused workaround */
	return 0;
}

