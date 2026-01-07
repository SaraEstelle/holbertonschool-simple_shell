#include "simple_shell.h"

/**
 * my_fork - Creates a child process and executes a command
 * @args: argument array
 * @argv: program name
 * @envp: environment variables
 */
int my_fork(char **args, char **argv, char **envp)
{
	pid_t pid;
	int status;
	char *cmd_path = NULL;
	int should_free = 0;
	struct stat st;

	if (!args || !args[0])
		return (0);

	/* Si la commande contient '/', c'est un chemin (absolu ou relatif) */
	if (_strchr(args[0], '/'))
	{
		if (stat(args[0], &st) == 0)
			cmd_path = args[0];
		else
		{
			fprintf(stderr, "%s:1 : %s: not found\n", argv[0], args[0]);
			return (127);
		}
	}
	else
	{
		/* Sinon, chercher dans PATH */
		char *path_env = my_getenv("PATH", envp);

		if (path_env && path_env[0] != '\0')
		{
			cmd_path = _which(args[0], path_env);
			should_free = 1;
		}

		if (!cmd_path)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
			return (127);
		}
	}
	/* Fork uniquement si la commande existe */
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		if (should_free)
			free(cmd_path);
		return (1);
	}

	if (pid == 0)
	{
		/* Child */
		execve(cmd_path, args, envp);
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
		exit(127);
	}

	else
	{
		/* parent */
		wait(&status);
		if (should_free)
			free(cmd_path);
	}
	if (WEXITSTATUS(status))
		return (WEXITSTATUS(status));
	return (1);
}
/* a recouper betty pas contente */
