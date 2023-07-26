#include "shell.h"

/**
 * my_exit - Exits the shell.
 * @info: Pointer to the structure containing potential arguments. Used to maintain constant function prototype.
 *
 * Return: Exits with a given exit status (0) if info->argv[0] != "exit". */
int my_exit(info_t *info)
{
	int exit_code;

	if (info->argv[1]) 
	{
		exit_code = str_to_int(info->argv[1]);
		if (exit_code == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_print_string(info->argv[1]);
			_print_char('\n');
			return 1;
		}
		info->err_num = str_to_int(info->argv[1]);
		return -2;
	}
	info->err_num = -1;
	return -2;
}

/**
 * my_cd - Changes the current directory of the process.
 * @info: Pointer to the structure containing potential arguments. Used to maintain constant function prototype.
 *
 * Return: Always 0.
 */
int my_cd(info_t *info)
{
	char *current_dir, *new_dir, buffer[1024];
	int chdir_ret;

	current_dir = getcwd(buffer, 1024);
	if (!current_dir)
		_print_string("TODO: >>getcwd failure emsg here<<\n");

	if (!info->argv[1])
	{
		new_dir = _getenv(info, "HOME=");
		if (!new_dir)
			chdir_ret = 
				chdir((new_dir = _getenv(info, "PWD=")) ? new_dir : "/");
		else
			chdir_ret = chdir(new_dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_print_string(current_dir);
			_print_char('\n');
			return 1;
		}
		_print_string(_getenv(info, "OLDPWD="));
		_print_char('\n');
		chdir_ret = 
			chdir((new_dir = _getenv(info, "OLDPWD=")) ? new_dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);

	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_print_string(info->argv[1]);
		_print_char('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return 0;
}

/**
 * my_help - Displays help information.
 * @info: Pointer to the structure containing potential arguments. Used to maintain constant function prototype.
 *
 * Return: Always 0.
 */
int my_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_print_string("help call works. Function not yet implemented \n");
	if (0)
		_print_string(*arg_array); 
	return 0;
}

