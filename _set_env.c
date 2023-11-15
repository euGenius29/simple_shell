#include "main.h"

/**
 * _set_env - Add or updates an environment variable with the name
 * @name to the value @value if @overwrite is set to
 * OVERWRITE.
 *
 * @name: The name for the environment variable to set
 * @value: The value to be added for the environment variable
 * @overwrite: When set to IGNORE, @value is not set. When
 * set to OVERWRITE, the value for the variable would be set
 *
 * Return: EXIT_SUCCESS should the process complete successfully
 * otherwise ERR_OCCURED is returned and errno is set
 * accordingly
*/
int _set_env(const char *name, const char *value, int overwrite)
{
	const char *matcher = NULL;
	node_t *node = NULL;

	matcher = _strstr(name, "=");
	if (name == NULL || matcher != NULL)
	{
		errno = EINVAL;
		return (ERR_OCCURED);
	}
	if (head != NULL)
	{
		node = _findnode(head,  (char *)name);
	}
	if (node == NULL)
	{
		_addnodeend(&head, (char *)name, (char *)value);
	}
	else
	{
		if  (overwrite == OVERWRITE)
		{
			node->value = (char *)value;
		}
	}
	return (EXIT_SUCCESS);
}

