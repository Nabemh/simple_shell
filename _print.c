#include "shell.h"

/**
 * _print - My custom print function
 * @text: string input
 *
 */

void _print(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
}
