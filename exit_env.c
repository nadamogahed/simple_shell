#include "main.h"
/**
 * exit_func - Exits the program
 * @args: The arguments passed to the program
 * @buffer: The buffer holding the arguments
 *
 * This function frees the arguments and the buffer, then exits the program.
 */
void exit_func(char **args, char *buffer)
{
	int ex;

	ex = (args[1] != NULL) ? _atoi(args[1]) : 0;
	free(args);
	free(buffer);
	_exit(ex);
}

/**
 * print_env - Prints the environment variables
 *
 * This function iterates over each environment variable and prints it.
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		print_string(environ[i]);
	}
}
