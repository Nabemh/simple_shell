#include "shell.h"

/**
 * _exe - executes the command passed to prompt
 *
 * @pmpt: command string to execute
 *
 */

void _exe(const char *pmpt)
{
	pid_t child_id, child_terminated;
	char *arg[128], *token;
	int arg_no, state;

	child_id = fork();

	if (child_id == -1)
	{
		perror("fork");
		_print("Error: Couldn't fork last process.\n");
		exit(EXIT_FAILURE);
	}
	if (child_id == 0)
	{
		token = strtok((char *)pmpt, " ");

		while (token != NULL && arg_no < 127)
		{
			arg[arg_no++] = token;
			token = strtok(NULL, " ");
		}

		arg[arg_no] = NULL;

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
			perror("waitpid\n");
			exit(EXIT_FAILURE);
		}
	}
}
