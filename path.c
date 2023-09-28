#include "main.h"
/**
 * getpath - Retrieves the value of a given environment variable
 * @name: The name of the environment variable to retrieve
 *
 * Return: If the environment variable is found, a string containing its value
 *         is returned. Otherwise, NULL is returned.
 */
char *getpath(char *name)
{
	int i = 0;
	char *path = NULL;

	while (environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], _len(name)) == 0)
		{
			path = _strdup(environ[i] + _len(name) + 1);
			break;
		}
		i++;
	}
	return (path);
}
/**
 * append_path - Appends the command to each PATH directory and checks if the
 *               resulting command is executable
 * @args: The command to append to each PATH directory
 *
 * Return: If an executable command is found, a string containing the command
 *         is returned. Otherwise, NULL is returned.
 */
char *append_path(char *args)
{
	char *path, *path_token, *cmd_path;
	int y = 0;

	path = getpath("PATH");
	if (path == NULL)
		return (NULL); /* handle error */
	path_token = strtok(path, ":");
	if (path_token == NULL || args == NULL)
	{
		free(path);
		return (NULL); /* handle error */
	}
	while (path_token != NULL)
	{
		cmd_path = malloc(_len(path_token) + _len(args) + 2);
		if (cmd_path == NULL)
		{
			free(path);
			return (NULL); /* handle error */
		}
		cmd_path[0] = '\0'; /* Reset the cmd_path buffer */
		_strcat(cmd_path, path_token);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, args);
		if (access(cmd_path, X_OK) == 0) /* Check if path is executable */
		{
			free(path);
			return (cmd_path);/* return a copy of cmd_path */
		}
		free(cmd_path);
		path_token = strtok(NULL, ":");
		y++;
	}
	free(path);
	return (NULL); /* free path_array */
}

