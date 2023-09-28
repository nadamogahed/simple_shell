#include "main.h"

/**
 * _len - prints triangle
 * @str: array of chars
 * Return: lenth of string
*/
int _len(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strncmp - compares two strings up to a certain length
 * @str_1: first string to compare
 * @str_2: second string to compare
 * @len: number of chars to compare
 * Return: 0  if the two strings are equal
 */

int _strncmp(char *str_1, char *str_2, int len)
{
	int i = 0, result = 0;
	char *str1, *str2;

	if (!str_1 || !str_2)
	{
		return (-1); /* handle the error */
	}
	str1 = _strdup(str_1);
	str2 = _strdup(str_2);
	while (len > 0)
	{
		/* Compare characters of str1 and str2 */
		if (str1[i] != str2[i])
		{
			result = (str1[i] - str2[i]);
			break;
		}
		i++;
		len--;
	}
	free(str1);
	free(str2);
	return (result);
}


/**
 * _strcat - concatenates two strings
 * @str_1: destination string
 * @str_2: source string
 *
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *str_1, char *str_2)
{
	int index = 0, len = 0;

	/* Find the length of the destination string */
	while (str_1[len] != '\0')
		len++;
	/* Append the source string to the destination string */
	while (str_2[index] != '\0')
	{
		str_1[len] = str_2[index];
		len++;
		index++;
	}
	/* Add null terminator */
	str_1[len] = '\0';
	return (str_1);
}

/**
 * _strdup - duplicates a string
 * @str_1: the string to duplicate
 *
 * Return: a pointer to the duplicated string, or NULL if fails
 */
char *_strdup(char *str_1)
{
	int len = 0, i = 0;
	char *str_2;

	/* Find the length of the input string */
	while (str_1[len] != '\0')
	{
		len++;
	}
	/* Allocate memory for the new string plus null character */
	str_2 = malloc(sizeof(char) * (len + 1));
	/* Check if memory allocation failed */
	if (str_2 == NULL)
	{
		return (NULL);
	}
	/* Copy the characters from the input string to the new string */
	while (i <= len)
	{
		str_2[i] = str_1[i];
		i++;
	}
	return (str_2);
}

