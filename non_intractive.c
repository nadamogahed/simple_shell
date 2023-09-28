#include "main.h"
/**
 * non_interactive - Handles the non-interactive mode of the shell
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on normal execution, error code on exit due to error
 */
int non_interactive(char *argv[]) {
    char *buffer = NULL, **command = NULL;
    ssize_t ret;
    int result, i;

    buffer = malloc(1204); /* Allocate memory for buffer */
    if (buffer == NULL) {
        perror("Failed to allocate memory for buffer");
        return 1;
    }
    ret = read(STDIN_FILENO, buffer, 1203);
    if (ret == -1 || ret == EOF ||  ret == 0) {
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
    while (command[i] != NULL) {
        i++;
        command[i] = strtok(NULL, "\n");
    }
    for (i = 0; command[i] != NULL; i++) {
        result = process_line(argv, command[i]);
    }
    free(command); /* Free the command after processing the line */
    free(buffer); /* Free the buffer after processing the line */
    buffer = NULL; /* Reset the buffer pointer */

    return (result);
}