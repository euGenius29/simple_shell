#include "main.h"

/**
 * _checkenv - Check whether the prompt accepted is the env command and display
 * the environment variables
 *
 * @command: The prompt accepted from the user
 *
 * Return: EXIT_SUCCESS when @command is indeed env otherwise
 * EXIT_FAILURE
*/
int _checkenv(char *command)
{
	char env[] = "env";
	int index = 0;

	if (command == NULL)
	{
		return (EXIT_FAILURE);
	}
	while (env[index] != '\0')
	{
		if (command[index] != env[index])
		{
			return (EXIT_FAILURE);
		}
		index++;
	}
	if (command[index] != '\0')
	{
		return (EXIT_FAILURE);
	}
	_printenv();
	signal_value = EXIT_SUCCESS;
	return (EXIT_SUCCESS);
}

/**
 * _check_file - Check for the exisitence of the file specified at @path
 *
 * @path: The path to the file to be executed
 *
 * Return: VALID_CMD if @path is a valid file,
 * NULL_FOUND if @path is NULL otherwise
 * INV_CMD
*/
int _check_file(char *path)
{
	if (path == NULL)
	{
		return (NULL_FOUND);
	}
	if (_isexec(path) == IS_EXEC)
	{
		if (access(path, F_OK) == VALID_CMD)
		{
			return (VALID_CMD);
		}
		return (INV_CMD);
	}
	if (_isrelpath(path) == IS_REL_PATH)
	{
		return (IS_REL_PATH);
	}
	if (access(path, F_OK) == VALID_CMD)
	{
		return (VALID_CMD);
	}
	return (INV_CMD);
}

/**
 * _check_mode - Determine whether the shell is running
 * in the interactive or the non-interactive mode
 *
 * Return: I_MODE if the user is in the interactive
 * mode otherwise NON_I_MODE
*/
int _check_mode(void)
{
	int mode;

	mode = isatty(STDIN_FILENO);
	if (mode == 1)
	{
		return (I_MODE);
	}
	return (NON_I_MODE);
}

/**
 * _checkpath - Check whether @command_path is an absolute or
 * relative path to the command to be executed
 *
 * @command_path: The command to be executed. Could be the
 * path to the command or merely the command name
 *
 * Return: VALID_CMD when @command_path is a valid absolute
 * path otherwise IS_REL_PATH to signify the command
 * name was accepted
*/
int _checkpath(char *command_path)
{
	return (_check_file(command_path));
}

