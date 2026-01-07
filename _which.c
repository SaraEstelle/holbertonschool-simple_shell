#include "simple_shell.h"
#include <sys/stat.h>

/**
 * _which - Finds full path of a command using PATH
 * @command: command to find
 * @path_env: PATH environment variable string
 * Return: malloc'ed full path, or NULL if not found
 */
char *_which(const char *command, const char *path_env)
{
	char *path_copy, *dir, *full_path;
	size_t len;

	if (command == NULL || path_env == NULL)
		return (NULL);

	path_copy = _strdup((char *)path_env);
	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		len = _strlen(dir) + 1 + _strlen((char *)command) + 1;
		full_path = malloc(sizeof(char) * len);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		snprintf(full_path, len, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
