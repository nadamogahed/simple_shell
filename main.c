#include "main.h"
/**
 * main - Entry point of the program
 *
 * Return: 0 on normal execution, error code on exit due to error
 */
int main(int argc, char *argv[])
{
    char *buffer = NULL, **command = NULL;
    size_t n = 0;
    ssize_t ret;
    int result, i;

    
        if (isatty(STDOUT_FILENO) && isatty(STDIN_FILENO))
        {
            while (1)
            {
                write(STDOUT_FILENO, "$ ", 2);
                ret = getline(&buffer, &n, stdin);
                if (ret == -1 || ret == EOF || ret == 0)
                {
                    free(buffer);
                    return (ret);
                }
                result = process_line(argc, argv, buffer);
                free(buffer); /* Free the buffer after processing the line */
                buffer = NULL; /* Reset the buffer pointer */
                n = 0; /* Reset n */
            }
        }
        else
        {
            buffer = malloc(1204); /* Allocate memory for buffer */
            if (buffer == NULL) {
                perror("Failed to allocate memory for buffer");
                return 1;
            }
            ret = read(STDIN_FILENO, buffer, 1203);
            if (ret == -1 || ret == EOF ||  ret == 0)
            {
                free(buffer);
                return (ret);
            }
            buffer[ret] = '\0'; /* Null-terminate the buffer */

            command = malloc(sizeof(char*) * 1024); /* Allocate memory for command */
            if (command == NULL) {
                perror("Failed to allocate memory for command");
                free(buffer);
                return 1;
            }

            i = 0;
            command[i] = strtok(buffer, "\n");
            while (command[i] != NULL)
            {
                i++;
                command[i] = strtok(NULL, "\n");
            }
            for (i = 0; command[i] != NULL; i++)
            {
                result = process_line(argc, argv, command[i]);
            }
            free(command); /* Free the command after processing the line */
            free(buffer); /* Free the buffer after processing the line */
            buffer = NULL; /* Reset the buffer pointer */
        }
    return (result);
}
