#include "main.h"

/**
 * _printenv - Prints the environment variables on the system
*/
void _printenv(void)
{
	int length = 0;
	node_t *current = NULL;

	current = head;
	while (current != NULL)
	{
		length = _strlen(current->name);
		write(STDOUT_FILENO, current->name, length);
		write(STDOUT_FILENO, "=", 1);
		if (current->value != NULL)
		{
			length = _strlen(current->value);
		}
		write(STDOUT_FILENO, current->value, length);
		write(STDOUT_FILENO, "\n", 1);
		current = current->next;
	}
}

/**
 * _print_err - Display an error message to stderr
 *
 * @commands_executed: The number of commands executed from the shell
 * @param_count: The number of arguments to be displayed
*/
void _print_err(int commands_executed, int param_count, ...)
{
	int size = 0, param_found = 0;
	va_list params;
	char *print_message;

	va_start(params, param_count);
	while (param_found < param_count)
	{
		print_message = va_arg(params, char *);
		size = _strlen(print_message) - 1;
		write(STDERR_FILENO, print_message, size);
		if (param_found == 1)
		{
			print_number(commands_executed);
		}
		param_found++;
	}
}

/**
 * print_number - Display the given integer.
 *
 * @number: The number to be displayed
 **/
void print_number(int number)
{
	int first = number, count = 0, x = 1, i, tmp;

	tmp = number;
	if (number < 0)
	{
		_putchar('-', STDERR_FILENO);
		number = (number * -1) - 1;
	}
	while (first != 0)
	{
		first = first / 10;
		count++;
	}
	while (x <= count)
	{
		first = number;
		i = x;
		while (i < count)
		{
			first = first / 10;
			i++;
		}
		if (tmp < 0 && x == count)
		{
			_putchar(((first % 10) + 48) + 1, STDERR_FILENO);
		}
		else
		{
			_putchar((first % 10) + 48, STDERR_FILENO);
		}
		x++;
	}
	if (count == 0)
	{
		_putchar('0', STDERR_FILENO);
	}
}
