#include "main.h"
/**
 * process_line - Processes a line of input
 * @argv: An array of pointers to the arguments
 * @buffer: The line of input to process
 *
 * Return: 0 on normal execution, error code on exit due to error
 */
int process_line(char *argv[], char *buffer)
{
	char **token, *temp = NULL;
	int i = 0, result;

	token = malloc(1024 * sizeof(char *));
	token[0] = strtok(buffer, " \n");
	/* check if the token is null or not */
	while (token[i] != NULL)
	{
		i++;
		token[i] = strtok(NULL, " \n");
	}
	/* if the first element is null free the token array */
	if (token[0] == NULL)
	{
		free(token);
		return (0);
	}
	/* check if first element in token is exit, env, / */
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
			print_error(argv, token);
			free(token); /* Handle error */
			return (127);
		}
		token[0] = NULL;
		token[0] = temp;
	}
	result = _exe(argv, token);
	free(temp); /* Free temp here */
	temp = NULL; /* Set temp to NULL after freeing */
	free(token);
	return (result);
}
