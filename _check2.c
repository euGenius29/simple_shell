#include "main.h"

/**
 * _isenvvarpath - Determine whether @env_variable is the PATH
 * environment variable
 *
 * @env_variable: The given environment variable
 *
 * Return: IS_PATH when @env_variable is a pointer to the PATH
 * environment variable otherwise IS_NOT_PATH
*/
int _isenvvarpath(char *env_variable)
{
	char path[] = "PATH";
	int index = 0;

	while (index < 4)
	{
		if (env_variable[index] != path[index])
		{
			return (IS_NOT_PATH);
		}
		index++;
	}
	return (IS_PATH);
}

/**
 * _isexec - Determines if @path is a path to
 * an executable
 *
 * @path: The path to the file to be executed
 *
 * Return: IS_EXEC if @path is a path to an executable
 * otherwise IS_REL_PATH
*/
int _isexec(char *path)
{
	char first_character;

	first_character = path[0];
	if (first_character == '.')
	{
		return (IS_EXEC);
	}
	return (IS_REL_PATH);
}

/**
 * _isrelpath - Determines if @path is a relative
 * path to a command with just the command name
 *
 * @path: The path to the file to be executed
 *
 * Return: IS_ABS_PATH if @path is an absolute file path
 * otherwise IS_REL_PATH
*/
int _isrelpath(char *path)
{
	char first_character;

	first_character = *path;
	if (first_character != '/')
	{
		return (IS_REL_PATH);
	}
	return (IS_ABS_PATH);
}

/**
 * _isexit - Determine whether the command obtained is the exit command
 *
 * @commands: A pointer to pointers containing commands obtained to be
 * freed
 * @buffer: A pointer to the buffer received after displaying the
 * prompt. This is also to be freed
 * @envpath: A pointer to a pointer of the PATH values
 * @signal_value: The exit code for the last command
 * @env_clone: The address to the temporary environment variable
 * that was created during program startup
*/
void _isexit(char **commands, char *buffer, char **envpath
, int signal_value, char **env_clone)
{
	int index = 0;

	if (commands[0] == NULL)
	{
		return;
	}
	if (EXIT)
	{
		_free_str(buffer);
		_free_array(commands);
		if (envpath != NULL)
		{
			_free_str(envpath[0]);
		}
		while (env_clone[index] != NULL)
		{
			_free_str(env_clone[index++]);
		}
		_free_array(env_clone);
		_free_array(envpath);
		free_list(head);
		exit(signal_value);
	}
}

