#include "main.h"


/**
 * _strdup - Creates a duplicate for the given string
 *
 * @str: The string to duplicate
 *
 * Return: A memory address to the newly allocated string.
 * Has the same contents @str
*/
char *_strdup(char *str)
{
	char *duplicate = NULL;
	int length = 0;

	length = _strlen(str);
	duplicate = malloc(sizeof(char) * length);
	_strcpy(duplicate, str);
	return (duplicate);
}

/**
 * _strlen - Return the length for given string including the
 * NULL terminating character.
 *
 * @str: The given string
 *
 * Return: The size for the given string
 **/
int _strlen(char *str)
{
	int total_characters = 0;

	while (str[total_characters] != '\0')
	{
		total_characters++;
	}
	return (total_characters + 1);
}

/**
 * _strcpy - Copy the string specified as source to the
 * specified destination. Appends the NULL terminating
 * character to @dest
 *
 * @src: The source string
 * @dest: The destination string
 *
 * Return: A pointer to the destination string
 **/
char *_strcpy(char *dest, char *src)
{
	int index_of_src = 0;

	while (src[index_of_src] != '\0')
	{
		dest[index_of_src] = src[index_of_src];
		index_of_src++;
	}
	dest[index_of_src] = '\0';
	return (dest);
}

/**
 * _strstr - Finds the first occurence of the substring
 * @needle in @haystack.
 *
 * @haystack: The string to be searched
 * @needle: The string to search for
 *
 * Return: A pointer to the memory address
 * which begins the located substring or NULL.
 *
 **/
const char *_strstr(const char *haystack, const char *needle)
{
	int count = 0, j = 0, ii = 0, s = 0;

	if (needle[ii] == '\0')
	{
		return (&haystack[ii]);
	}
	for ( ; needle[s]; s++)
	{
	}
	for ( ; needle[ii]; ii++)
	{
		j = ii;
		for ( ; haystack[j]; j++)
		{
			if (needle[ii] == haystack[j])
			{
				count++;
				j++;
				break;
			}
		}
	}
	if (count == s)
	{
		return (&haystack[j - s]);
	}
	return (NULL);
}

/**
 * _strcmp - compares two strings.
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: negative number if s1 < s2,
 * positive number if s1 > s2
 * and 0 if s1 is equal to s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] || s2[i]; i++)
	{
		if (s1[i] != s2[i])
		break;
	}
	return (s1[i] - s2[i]);
}
