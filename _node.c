#include "main.h"

/**
 * _findnode - Locate the node with the name @name from the list of
 * environment variables
 *
 * @head: The head node in the list of environment variables
 * @name: The name for the variable searched for
 *
 * Return: The node with the name value same as @name
*/
node_t *_findnode(node_t *head, char *name)
{
	node_t *current = NULL;

	current = head;
	while (current->next != NULL)
	{
		if (_strcmp(current->name, name) == EQUAL_STR)
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

/**
 * _addnodeend - Add a new environment variable to the list of environment
 * variables.
 *
 * @head: The head node in the list.
 * @name: The name for the environment variable to be added as the tail
 * @value: The value for the environment variable to be added
 *
 * Return: The address to the newly added node at the end of the list
*/
node_t *_addnodeend(node_t **head, char *name, char *value)
{
	node_t *tail, *current;

	tail = malloc(sizeof(node_t));
	tail->name = name;
	tail->value = value;
	tail->next = NULL;

	if (*head == NULL)
	{
		*head = tail;
		return (tail);
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = tail;
	return (tail);
}

