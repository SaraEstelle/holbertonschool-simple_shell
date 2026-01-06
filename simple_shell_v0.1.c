#include "simple_shell.h"

/**
 *
 *
 */

// prototype
/* 1. Déclarations (line = NULL, len = 0, argv_command[2]...) */

while (1) /* La boucle infinie */
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

	/* 5. Nettoyage : remplacer le '\n' par '\0' à l'index [nread - 1] */

	argv[0] = line;
	argv[1] = NULL;

	child_pid = fork(); /* 7. Création du fils avec fork() */
	if (child_pid == -1)
	{
		perror("Error :");
		return (1);
	}
	if (child_pid == 0) /* 8. DANS LE FILS (if pid == 0) :
		   Appeler execve(argv_command[0], argv_command, environ);
		   SI on arrive ici, c'est que ça a échoué -> perror(av[0]); exit(1);
	 */

	{
		execve(argv_command[0], argv_command, NULL);
		perror("Execve Failled !!");
		return (1);
	}
	else /* 9. DANS LE PERE (else) :
		 Appeler wait(&status);
   */
	{
		wait(&status);
		printf(" Enfant %d a fini son travail\n", i);
		i++;
	}
}
