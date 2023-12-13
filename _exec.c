#include "shell.h"

/**
 * token - Tokenize the input string and create an array of arguments
 *
 * @pmpt: command string to tokenize
 * @arg: array of pointers to store the arguments
 *
 * Return: Number of arguments
 */
int token(const char *pmpt, char *arg[128])
{
	int arg_no = 0, position = 0;
	size_t i;

	for (i = 0; pmpt[i] != '\0'; ++i)
	{
		if (pmpt[i] == ' ' || pmpt[i] == '\t' || pmpt[i] == '\n')
		{
			if (position > 0)
			{
				arg[arg_no] = malloc(position + 1);
				if (arg[arg_no] == NULL)
				{
					perror("malloc");
					exit(EXIT_FAILURE);
				}
				memcpy(arg[arg_no], &pmpt[i - position], position);
				arg[arg_no][position] = '\0';
				arg_no++;
				position = 0;
			}
		}
		else
		{
			position++;
		}
	}
	if (position > 0)
	{
		arg[arg_no] = malloc(position + 1);
		if (arg[arg_no] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		memcpy(arg[arg_no], &pmpt[strlen(pmpt) - position], position);
		arg[arg_no][position] = '\0';
		arg_no++;
	}
	arg[arg_no] = NULL;
	return (arg_no);
}

/**
 * _exe - Tokenize and execute the command
 *
 * @pmpt: command string to execute
 */
void _exe(const char *pmpt)
{
	char *arg[128];
	int state, i;
	pid_t child_id, child_terminated;

	child_id = fork();

	if (child_id == -1)
	{
		perror("fork");
		_print("Error: Couldn't fork last process.\n");
		exit(EXIT_FAILURE);
	}

	if (child_id == 0)
	{
		token(pmpt, arg);
		if (execve(arg[0], arg, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		child_terminated = waitpid(child_id, &state, 0);

		if (child_terminated == -1)
		{
		perror("waitpid");
		exit(EXIT_FAILURE);
		}

		for (i = 0; arg[i] != NULL; i++)
		{
			free(arg[i]);
		}
	}
}

