#include "shell.h"

/**
 *int main - fonction that print $
 *
 *Return: -1 or 0.
 */

int main(void)
{
	char *caractere = NULL;
	size_t lenght = 0;
	ssize_t bytes_read = 0;

	printf(" $");

	bytes_read = getline(&caractere, &lenght, stdin);

	if (bytes_read == -1)
	{
		free(caractere);
		return (0);
	}
	printf("%s", caractere);
	free(caractere);
	return(0);
}
