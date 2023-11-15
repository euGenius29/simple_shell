#include "main.h"

/**
 * _exitshell - Clean up memory before exiting shell
 *
 * @envpath: A pointer to the environment PATH variables
 * @env_clone: A pointer to a copy of the users environment variables
 * @buffer: The command accepted from the user
 *
 * Return: the exit code for the last successfull command
 */
int _exitshell(char **envpath, char **env_clone, char *buffer)
{
	int index = 0;

	if (envpath != NULL)
	{
		_free_str(envpath[0]);
	}
	while (env_clone[index] != NULL)
	{
		_free_str(env_clone[index++]);
	}
	_free_array(env_clone);
	_free_str(buffer);
	_free_array(envpath);
	free_list(head);
	return (signal_value);
}

/**
 * _exec - Execute the given command
 *
 * @commands: The given command to be executed along with its
 * arguments (if any)
 * @commands_executed: The number of commands executed from the shell
 * @program: The name for the shell
 * @env: The memory address to the cloned copy of the environment
 * variables
 *
 * Return: The exit code for the child process created.
 * Would also return an appropriate exit code should an error occur
*/
int _exec(char **commands, int commands_executed, char *program, char **env)
{
	char *pathname = NULL;
	int status = 0;
	pid_t pid;
	int file_info = VALID_CMD;

	pathname = commands[0];
	file_info = _check_file(pathname);
	if (file_info == VALID_CMD)
	{
		pid = fork();
		if (pid == -1)
		{
			return (errno);
		}
		if (pid == 0)
			{
			signal_value = EXIT_SUCCESS;
			if (execve(pathname, commands, env) == ERR_OCCURED)
			{
				signal_value = status;
				exit(EXIT_FAILURE);
			}
		}
		wait(&status);
		if (WIFEXITED(status))
		{
			signal_value = (WEXITSTATUS(status));
			return (WEXITSTATUS(status));
		}
	}
	else if (file_info == INV_CMD || file_info == IS_REL_PATH)
	{
		_print_err(commands_executed, 5, program, ": ",
		": ", pathname, ": not found\n");
		signal_value = INV_CMD;
		return (INV_CMD);
	}
	return (status);
}

