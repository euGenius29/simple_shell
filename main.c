#include "main.h"

void handle_sigint(int signum);

int signal_value = 0;
node_t *head = NULL;

/**
 * main - Shell intry point
 *
 * @argc: The number of arguments
 * @argv: The list of arguments given
 * @env: The environment variables received from the
 * users system
 *
 * Return: The appropriate exit code for the shell
*/
int main(int argc __attribute__((unused)), char *argv[], char *env[])
{
	char *buffer = NULL;
	char **commands = NULL,  **envpath = NULL, **env_clone = NULL;
	size_t bytes_read = 0;
	int commands_executed = 0;
	int exit_code = NULL_FOUND, file_info = VALID_CMD;

	signal(SIGINT, handle_sigint);
	env_clone = _get_envs(env);
	_set_env(SHLVL_NAME, SHLVL_VAL, IGNORE);
	envpath = _loadpaths(head);
	while (1)
	{
		commands_executed++;
		exit_code = NULL_FOUND;
		if (_accept(&buffer, &bytes_read) == EOF)
			return (_exitshell(envpath, env_clone, buffer));
		commands = _tokenize(buffer, " \t\r\n");
		_isexit(commands, buffer, envpath, signal_value, env_clone);
		if (_checkenv(commands[0]) == EXIT_SUCCESS)
		{
			_free_array(commands);
			continue;
		}
		file_info = _check_file(commands[0]);
		_relpath(&file_info, envpath, commands, buffer, &exit_code);
		exit_code = _exec(((exit_code == SIG_CODE) ?
		&buffer : commands), commands_executed, argv[0], env);
		if (exit_code == EXIT_SUCCESS && file_info == IS_REL_PATH)
		{
			_free_str(commands[0]);
		}
		_free_array(commands);
	}
	return (exit_code);
}
