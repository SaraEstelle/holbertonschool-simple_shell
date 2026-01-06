#include "simple_shell.h"

/**
 *run_shell - function that run a shell
 *@shell_state: state of shell
 *@argv: arguments
 *@envp: environnement
 *
 */

void run_shell(simple_shell_t *shell_state, char **argv, char **envp)
{
	char *line;
	int arg_count;
	char *args[2]; /* Pour la v0.1 : commande + NULL */

	while (1)
	{
		if (shell_state->is_interactive)
			write(1, "#cisfun$ ", 9);

		line = read_line(); /* Étape 3 de ton plan */
		if (!line)			/* Gestion du Ctrl+D */
			break;
		arg_count = parse_args(line, args);
		if (arg_count > 0)
		{
			my_fork(args, argv, envp);
		}

		if (arg_count == 0) /* Étape 5 & 6 : Nettoyage et préparation */
		{
			my_fork(args, argv, envp); /* Étape 7, 8 & 9 : Fork, Exec, Wait */
		}

		free(line); /* On libère SEULEMENT ici, après l'exécution */
	}
}
