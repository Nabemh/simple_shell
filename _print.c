#include "shell.h"

void _print(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text))
}
