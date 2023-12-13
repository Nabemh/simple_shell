#include "shell.h"


/**
 * prompt - reads the user prompt
 * 
 * @command: Pointer to a character of arraus to store the user input
 * @size: Size of the character array
 */

void prompt(char *command, size_t size)
{

	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			_print("Error\n");
			exit(EXIT_FAILURE);
		}
	}
	
	for (size_t i = 0; i < size; i++)
	{
		if (command[i] == '\n')
		{
			command[i] = '\0';
		}
		else
		{
			_print("input too long\n");
			exit(EXIT_FAILURE);
	}
}
