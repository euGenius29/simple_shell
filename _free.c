#include "main.h"

/**
 * _free_array - Frees memory allocated to commands to be executed by the shell
 *
 * @commands: The given commands to be executed
*/
void _free_array(char **commands)
{
	free(commands);
	commands = NULL;
}

/**
 * _free_str - Frees memory allocated to any string used in the shell that
 * needs to be freed
 *
 * @str: A string that needs to be freed
*/
void _free_str(char *str)
{
	free(str);
	str = NULL;
}

/**
 * free_list - frees a linked list
 *
 * @head: the head node of the list
 */
void free_list(node_t *head)
{
	if (head == NULL)
		return;
	if (head->next == NULL)
	{
		free(head);
		return;
	}
	free_list(head->next);
	free(head);
}

