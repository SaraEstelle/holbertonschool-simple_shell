#include "simple_shell.h"

#define MAX_ARGS 64

/**
 * run_shell - Main loop of the shell
 * @shell_state: pointer to shell state structure
 * @argv: program name
 * @envp: environment variables
 */
void run_shell(simple_shell_t *shell_state, char **argv, char **envp)
{
	char *line;
	char *args[MAX_ARGS];
	int argc, builtin_executed;

	while (1)
	{
		shell_state->is_interactive = isatty(STDIN_FILENO);

		if (shell_state->is_interactive)
			printf("($) ");

		line = read_line();
		if (line == NULL) /* EOF */
		{
			if (shell_state->is_interactive)
				printf("\n");
			break;
		}

		argc = parse_args(line, args);
		if (argc == 0)
		{
			free(line);
			continue;
		}

		/* Check builtins */
		builtin_executed = 0;

		if (_strcmp(args[0], "exit") == 0)
		{
			exit_command(line);
		}
		else if (_strcmp(args[0], "env") == 0)
		{
			env_command(envp);
			builtin_executed = 1;
		}

		/* Execute external command */
		if (!builtin_executed)
			my_fork(args, argv, envp);

		free(line);
	}
}

/**
 * main - Entry point of the shell
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variables
 * Return: 0 on success
 */
int main(int argc, char **argv, char **envp)
{
	simple_shell_t shell_state;

	(void)argc; /* unused */

	run_shell(&shell_state, argv, envp);

	return (0);
}
