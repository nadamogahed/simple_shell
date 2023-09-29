#include "main.h"
/**
 * _exe - Executes a command
 * @argv: The arguments entered
 * @args: The arguments for the command
 *
 * This function forks a new process and tries to execute the command.
 * If the command fails, it prints an error message and exits.
 * Return: -1 on fail
 */
int _exe(char *argv[], char **args)
{
	int child, status, exit_status;

	child = fork();
	if (child == -1)
	{
		perror("fork");
		free(args);
		return (2);
	}
	else if (child == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			print_error(argv, args);
			return (127);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			return (exit_status);
		}
	}
	return (0);
}
