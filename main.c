#include "main.h"
/**
 * main - Entry point of the program
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 *
 * Description: This function checks if
 * the standard output and input are
 * connected to a terminal.
 * If they are, it calls the function 'interactive'
 * with 'argv' as the argument. If they are not, it calls the function
 * 'non_interactive' with 'argv' as the argument.
 *
 * Return: The return value of either 'interactive' or 'non_interactive'
 */
int main(int argc, char *argv[])
{
	(void)argc;
	if (isatty(STDOUT_FILENO) && isatty(STDIN_FILENO))
	{
		return (interactive(argv));
	}
	else
	{
		return (non_interactive(argv));
	}
}
