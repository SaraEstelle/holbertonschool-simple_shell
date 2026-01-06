#include "simple_shell.h"

/**
 * read_line - Reads a line from standard input
 * Return: pointer to the line read, or NULL on EOF or failure
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&line, &bufsize, stdin);

	if (nread == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
