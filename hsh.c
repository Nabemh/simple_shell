#include "shell.h"

/**
 * main - Entry point to my h_shell
 *
 * Return: 0
 */

int main(void)
{
	char user_input[128];

	while (1)
	{
		_print("#cisfun$ ");
		prompt(user_input, sizeof(user_input));
		_exe(user_input);
	}
	return (0);
}
