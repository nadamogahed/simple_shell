#include "main.h"
/**
 * allocate_buffer - Allocates or reallocates a buffer if necessary
 * @lineptr: pointer to the buffer to hold the line
 * @n: pointer to the size of the buffer
 * @len: current length of the line
 *
 * Return: 0 on success, or -1 on error
 */
int allocate_buffer(char **lineptr, size_t *n, size_t len)
{
	if (*lineptr == NULL || *n == 0)
	{
		*n = 120;
		*lineptr = malloc(*n);
	}
	else if (len + 2 > *n)
	{
		*n *= 2;
		*lineptr = realloc(*lineptr, *n);
	}
	if (*lineptr == NULL)
	{
		return (-1);
	}
	return (0);
}

/**
 * readline - reads a line from a file descriptor
 * @lineptr: pointer to the buffer to hold the line
 * @n: pointer to the size of the buffer
 * @fd: file descriptor to read from
 *
 * Return: number of characters read, or -1 on error
 */
ssize_t readline(char **lineptr, size_t *n, int fd)
{
	ssize_t len = 0; /* number of characters read */
	char ch; /* current character */
	ssize_t ret; /* return value of read */

	while (1) /* read characters one by one */
	{
		ret = read(fd, &ch, 1);
		/* check for read error or end of file */
		if (ret <= 0)
		{
			break;
		}
		/* allocate or reallocate buffer if necessary */
		if (allocate_buffer(lineptr, n, len) == -1)
		{
			return (-1);
		}
		/* store character in buffer */
		(*lineptr)[len++] = ch;
		/* stop reading if newline is found */
		if (ch == '\n')
		{
			break;
		}
	}
	/* null-terminate the buffer */
	if (len > 0)
		(*lineptr)[len] = '\0';
	return (len > 0 ? len : -1); /* return number of characters read */
}
