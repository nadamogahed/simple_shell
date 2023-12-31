#include "main.h"
/**
 * print_error - prints a string
 * @argv: An array of pointers to the arguments
 * @token: an arry pointer
 * Return: void
 */
int print_error(char *argv[], char **token)
{
	int re = 0;

	if (token == NULL)
		re += write(STDOUT_FILENO, "(null)", 6);
	else
	{
		re += write(STDERR_FILENO, argv[0], _len(argv[0]));
		re += write(STDERR_FILENO, ": 1: ", 5);
		re += write(STDERR_FILENO, token[0], _len(token[0]));
		re += write(STDERR_FILENO, ": not found\n", 12);
	}
	return (re);
}
