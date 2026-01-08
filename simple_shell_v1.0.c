#include "simple_shell.h"

/**
 * handle_builtin - executes built-in commands if found
 * @args: array of arguments
 * @shell_state: current shell state
 * @envp: environment variables
 *
 * Return:
 * -1 if exit is requested
 *  1 if a built-in was executed,
 *  0 otherwise
 */
int handle_builtin(char **args, simple_shell_t *shell_state, char **envp)
{
	(void)shell_state;

	if (_strcmp(args[0], "exit") == 0)
		return (-1);

	if (_strcmp(args[0], "env") == 0)
	{
		_printenv(envp);
		return (1);
	}

	return (0);
}

/**
 * execute_command - executes an external command using my_fork
 * @args: array of arguments
 * @argv: program name
 * @envp: environment variables
 * @shell_state: current shell state
 */
void execute_command(char **args, char **argv, char **envp,
					 simple_shell_t *shell_state)
{
	shell_state->exit_status = my_fork(args, argv, envp,
									   shell_state->cmd_count);
	shell_state->cmd_count++;
}

/**
 * run_shell - main loop to run the shell
 * @shell_state: state of the shell
 * @argv: program name
 * @envp: environment variables
 */
void run_shell(simple_shell_t *shell_state, char **argv, char **envp)
{
	char *line;
	int arg_count;
	int builtin_status;
	char *args[64];

	while (1)
	{
		if (shell_state->is_interactive)
			write(1, "($) ", 4);

		line = read_line();
		if (!line)
			break;

		arg_count = parse_args(line, args);
		if (arg_count == 0 || args[0] == NULL)
		{
			free(line);
			continue;
		}

		builtin_status = handle_builtin(args, shell_state, envp);

		if (builtin_status == -1)
		{
			free(line);
			exit(shell_state->exit_status);
		}

		if (builtin_status == 1)
		{
			free(line);
			continue;
		}

		execute_command(args, argv, envp, shell_state);
		free(line);
	}
}
