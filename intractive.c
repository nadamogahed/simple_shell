#include "main.h"
/**
 * interactive - Handles the interactive mode of the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on normal execution, error code on exit due to error
 */
int interactive(char *argv[])
{
    char *buffer = NULL;
    size_t n = 0;
    ssize_t ret;
    int result;

    while (1)
    {
        write(STDOUT_FILENO, "$ ", 2);
        ret = getline(&buffer, &n, stdin);
        if (ret == -1 || ret == EOF || ret == 0) {
            free(buffer);
            return (ret);
        }
        result = process_line(argv, buffer);
        free(buffer); /* Free the buffer after processing the line */
        buffer = NULL; /* Reset the buffer pointer */
        n = 0; /* Reset n */
    }
    return (result);
}