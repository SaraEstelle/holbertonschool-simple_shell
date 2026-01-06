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

		line = read_line();
		if (!line)			/* Gestion du Ctrl+D */
			break;
		arg_count = parse_args(line, args);

		if (args[0] == NULL)
			continue;

		if (strcmp(args[0], "exit") == 0)/* commande exit*/
		{
			exit(0);
		}

		if (arg_count == 0 || args[0] == NULL)/*Nettoyage et préparation */
		{
			free(line);
			my_fork(args, argv, envp); /* Fork, Exec, Wait */
		}
		/* Builtin: env */
		if (_strcmp(args[0], "env") == 0)
		{
			_printenv(envp);
			free(line);
			continue;
		}
		/* Commande externe */
		my_fork(args, argv, envp);
		free(line); /* On libère */
	}
}
