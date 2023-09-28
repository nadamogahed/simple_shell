#include "main.h"
/**
 * process_line - Processes a line of input
 * @buffer: The line of input to process
 *
 * Return: 0 on normal execution, error code on exit due to error
 */

int process_line(int argc, char *argv[], char *buffer)
{
	char **token, *temp = NULL;
	int i = 0, result;

	token = malloc(1024 * sizeof(char *));
	token[0] = strtok(buffer, " \n");
	while (token[i] != NULL)
	{
		i++;
		token[i] = strtok(NULL, " \n");
	}
	if (token[0] == NULL)
	{
		free(token);
		return (0);
	}
	if (_strncmp(token[0], "exit", 4) == 0)
		exit_func(token, buffer);
	else if (_strncmp(token[0], "env", 3) == 0)
	{
		print_env();
		free(token);
		return (0);
	}
	else if (_strncmp(token[0], "/", 1) != 0 && _strncmp(token[0], ".", 1) != 0)
	{
		temp = append_path(token[0]);
		if (temp == NULL)
		{
			print_error(argc , argv, token);
			free(token); /* Handle error */
			return (127);
		}
		token[0] = NULL;
		token[0] = temp;
	}
	result = _exe(argc, argv, token);
	if(temp != NULL)
	{
	    free(temp); // Free temp here
	    temp = NULL; // Set temp to NULL after freeing
    }
	free(token);
	return (result);
}
