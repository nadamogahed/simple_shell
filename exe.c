#include "main.h"
/**
 * _ exe - Executes a command
 * @args: The arguments for the command
 *
 * This function forks a new process and tries to execute the command.
 * If the command fails, it prints an error message and exits.
 * Return: -1 on fail
 */
int _exe(int argc, char *argv[], char **args)
{
	int child, status, exit_status;

	/*if (access(args[0], X_OK) == 0)
	{*/
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
				print_error(argc , argv, args);
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
	/*}
	else
	{
		perror("access");
		free(args);
		return (127);
	}*/
	return (0);
}
