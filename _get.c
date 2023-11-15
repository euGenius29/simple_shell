#include "main.h"

/**
 * _getenvpathvar - Obtain the PATH from the environment variables
 *
 * Return: The value of the PATH variable from the environment variables
*/
char *_getenvpathvar()
{
	char *path = NULL;
	char *path_value = NULL;
	node_t *current = NULL;

	current = head;
	while (current != NULL)
	{
		path = current->name;
		if (_isenvvarpath(path) == IS_PATH)
		{
			path_value = current->value;
			break;
		}
		current = current->next;
	}
	return (path_value);
}

/**
 * _get_envs - Get the environment variables as a list
 *
 * @env: A pointer to the system's environment variable
 *
 * Return: The memory address to a copy of the environment variables
*/
char **_get_envs(char **env)
{
	int index = 0, variables_count = 0;
	char *name = NULL, *value = NULL;
	char **env_clone = NULL;

	while (env[variables_count] != NULL)
	{
		variables_count++;
	}
	env_clone = malloc(sizeof(char *) * (variables_count + 1));
	while (env[index] != NULL)
	{
		env_clone[index] = _strdup(env[index]);
		index++;
	}
	env_clone[index] = NULL;
	index = 0;
	while (env_clone[index] != NULL)
	{
		name = strtok(env_clone[index], "=");
		value = strtok(NULL, "\n");
		_addnodeend(&head, name, value);
		index++;
	}
	index = 0;
	return (env_clone);
}


/**
 * _get_fullpath - Obtain the full PATH to @command
 *
 * @path: A path in the PATH environment variable
 * @command: The given command to be executed
 *
 * Return: The full path to @command
*/
char *_get_fullpath(char *path, char *command)
{
	return (_pathbuilder(3, path, "/", command));
}

