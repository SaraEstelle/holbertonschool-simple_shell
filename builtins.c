#include "simple_shell.h"

/**
 * exit_command - Exits the shell
 * @line: input line (to free)
 * Return: never returns if executed
 */
int exit_command(char *line)
{
	if (line != NULL)
		free(line);

	exit(0);
}

/**
 * env_command - Prints the current environment variables
 * @envp: environment array
 * Return: 0
 */
int env_command(char **envp)
{
	int i;

	if (envp == NULL)
		return (0);

	for (i = 0; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
	}

	return (0);
}
