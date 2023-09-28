#include "main.h"
/**
 * _atoi - converts a string of digits into an integer
 * @str: the string to convert
 *
 * Return: the integer value represented by the input string
 */
int _atoi(char *str)
{
	int i = 0, integer = 0;

	/* Handle the case where the input string is NULL */
	if (str == NULL)
	{
		return (0);
	}
	/* Iterate over the characters in the input string */
	while (str[i])
	{
		/* Check if the current character is a digit */
		if (str[i] >= '0' && str[i] <= '9')
		{
			/* Update the integer value */
			integer = integer * 10 + (str[i] - '0');
		}
		i++;
	}
	return (integer);
}
