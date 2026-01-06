#include "simple_shell.h"

/**
 * my_getenv - Retrieves the value of an environment variable
 * @name: name of the environment variable
 * @envp: environment array
 * Return: pointer to value or NULL if not found
 */
char *my_getenv(const char *name, char **envp)
{
	int i;
	size_t name_len;

	if (name == NULL || envp == NULL)
		return (NULL);

	name_len = _strlen((char *)name);

	for (i = 0; envp[i] != NULL; i++)
	{
		if (_strncmp(envp[i], name, name_len) == 0 &&
			envp[i][name_len] == '=')
			return (envp[i] + name_len + 1);
	}
	return (NULL);
}

/**
 * main - program that prints the environment
 * using the global variable environ
 *
 * Return: Always 0.
 */

int _printenv(char **envp)
{
	unsigned int i = 0;

	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}
