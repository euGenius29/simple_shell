#include "main.h"

/**
 * handle_sigint - Callback function to handle Ctrl + C signal
 *
 * @signum: The signal number obtained
*/
void handle_sigint(int signum __attribute__((unused)))
{
	signal_value = SIG_CODE;
	write(STDOUT_FILENO, "\n$ ", 3);
}
