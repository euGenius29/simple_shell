#include "main.h"

/**
 * _pathbuilder - Appends the given string @str to @src
 * forming a file path
 *
 * @argc: The number of strings to be appended to @src
 *
 * Return: A pointer to a new memory address with the newly combines
 * path
*/
char *_pathbuilder(int argc, ...)
{
	va_list args;
	char *str = NULL, *newstr = NULL;
	int args_found = 0, index = 0, str_index = 0, length = 0;

	va_start(args, argc);
	while (args_found < argc)
	{
		str = va_arg(args, char *);
		length += _strlen(str);
		args_found++;
	}
	va_end(args);
	args_found = 0;
	newstr = malloc(sizeof(char) * length);
	va_start(args, argc);
	while (args_found < argc)
	{
		str = va_arg(args, char *);
		str_index = 0;
		while (str[str_index] != '\0')
		{
			newstr[index++] = str[str_index++];
		}
		args_found++;
	}
	va_end(args);
	newstr[index] = '\0';
	return (newstr);
}


/**
 * _loadpaths - Retrieves the values for the PATH environment variable
 *
 * @head: The head node in the list of environment variables
 *
 * Return: A pointer to a pointer of the PATH values
*/
char **_loadpaths(node_t *head)
{
	char **paths = NULL;
	char *var_name = NULL, *var_value = NULL;
	node_t *current = NULL;
	int length = 0;

	current = head;
	while (current != NULL)
	{
		var_name = current->name;
		if (_isenvvarpath(var_name) == IS_PATH)
		{
			length = _strlen(current->value);
			var_value = malloc(sizeof(char) * length);
			_strcpy(var_value, current->value);
			break;
		}
		current = current->next;
	}
	if (var_value != NULL)
	{
		paths = _tokenize(var_value, ":");
	}
	return (paths);
}

