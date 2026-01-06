#include "simple_shell.h"

#define MAX_ARGS 64

/**
 * parse_args - Splits a line into arguments
 * @line: input line
 * @args: array to store arguments
 * Return: number of arguments
 */
int parse_args(char *line, char **args)
{
	int i = 0;
	char *token;

	if (line == NULL || args == NULL || line[0] == '\0')
		return (0);

	/* Remove trailing newline */
	token = _strchr(line, '\n');
	if (token)
		*token = '\0';

	token = strtok(line, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;
	return (i);
}
