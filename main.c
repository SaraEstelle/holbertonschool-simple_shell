#include "simple_shell.h"

/**
 * main - entry point of the shell v0.3
 * @argc: argument count (unused)
 * @argv: program name and arguments
 * @envp: environment variables
 * Return: 0
 */
int main(int argc, char **argv, char **envp)
{
	simple_shell_t shell_state;

	(void)argc;

	/* Détecter si le shell est interactif */
	shell_state.is_interactive = isatty(STDIN_FILENO);
	shell_state.exit_status = 0;
	shell_state.cmd_count = 1;

	/* Lancer la boucle principale du shell */
	run_shell(&shell_state, argv, envp);

	return (shell_state.exit_status);
}
