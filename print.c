#include "main.h"
/**
 * print_string - prints a string
 * @string: an arry pointer
 * Return: void
 */
int print_string(char *string)
{
	int re = 0;

	if (string == NULL)
		re += write(STDOUT_FILENO, "(null)", 6);
	else
	{
		re += write(STDOUT_FILENO, string, _len(string));
		re += write(STDOUT_FILENO, "\n", 1);
	}
	return (re);
}
