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
	char *args[64]; /* Tableau plus grand pour plusieurs arguments */

	while (1)
	{
		if (shell_state->is_interactive)
			write(1, "#(o_o)$ ", 9);

		line = read_line();
		if (!line)
			break;

		arg_count = parse_args(line, args);

		if (arg_count == 0 || args[0] == NULL)
		{
			free(line);
			continue;
		}

		/* Builtin: exit marche pas*/
		if (_strcmp(args[0], "exit") == 0)
		{
			exit_command(line);
		}

		/* Builtin: env marche */
		if (_strcmp(args[0], "env") == 0)
		{
			_printenv(envp);
			free(line);
			continue;
		}

		/* Commande externe */
		my_fork(args, argv, envp);
		free(line);
	}
}
