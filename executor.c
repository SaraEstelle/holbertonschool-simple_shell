#include "simple_shell.h"

/**
 * my_fork - Creates a child process and executes a command
 * @args: argument array
 * @argv: program name
 * @envp: environment variables
 * @cmd_count: command counter for error messages
 * Return: exit status of the command
 */
int my_fork(char **args, char **argv, char **envp, int cmd_count)
{
	pid_t pid;
	int status;
	char *cmd_path = NULL;
	int should_free = 0;

	if (!args || !args[0])
		return (0);

	/* Si la commande contient '/', c'est un chemin (absolu ou relatif) */
	if (_strchr(args[0], '/'))
	{
		if (access(args[0], X_OK) == 0)
			cmd_path = args[0];
		else
		{
			fprintf(stderr, "%s: %d: %s: not found\n", argv[0], cmd_count, args[0]);
			return (127);
		}
	}
	else
	{
		/* Sinon, chercher dans PATH */
		char *path_env = my_getenv("PATH", envp);

		if (path_env != NULL && path_env[0] != '\0')
		{
			cmd_path = _which(args[0], path_env);
			should_free = 1;
		}

		if (!cmd_path)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", argv[0], cmd_count, args[0]);
			return (127);
		}
	}
	/* Fork uniquement si la commande existe */
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		if (should_free && cmd_path != NULL)
			free(cmd_path);
		return (1);
	}

	if (pid == 0)
	{
		/* Child */
		if (execve(cmd_path, args, envp) == -1)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", argv[0], cmd_count, args[0]);
			if (should_free)
				free(cmd_path);
			exit(127);
		}
	}
	else
	{
		/* parent */
		wait(&status);
		if (should_free && cmd_path != NULL)
			free(cmd_path);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (0);
}
/* a recouper betty pas contente */