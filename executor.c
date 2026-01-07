#include "simple_shell.h"

/**
 * my_fork - Creates a child process and executes a command
 * @args: argument array
 * @argv: program name
 * @envp: environment variables
 */
void my_fork(char **args, char **argv, char **envp)
{
	pid_t pid;
	int status;
	char *cmd_path;
	int should_free = 0;
	struct stat st;

	if (args == NULL || args[0] == NULL)
		return;

	/* Si la commande contient '/', c'est un chemin (absolu ou relatif) */
	if (_strchr(args[0], '/') != NULL)
	{
		if (stat(args[0], &st) == 0)
			cmd_path = args[0];
		else
		{
			fprintf(stderr, "./shell: %s: No such file or directory\n", args[0]);
			return;
		}
	}
	else
	{
		/* Sinon, chercher dans PATH */
		cmd_path = _which(args[0], my_getenv("PATH", envp));
		should_free = 1;
		if (cmd_path == NULL)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
			exit(127);
		}
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		if (should_free)
			free(cmd_path);
		return;
	}

	if (pid == 0)
	{
		if (execve(cmd_path, args, envp) == -1)
		{
			perror(argv[0]);
			if (should_free)
				free(cmd_path);
			exit(1);
		}
	}
	else
	{
		wait(&status);
		if (should_free)
			free(cmd_path);
	}
}
/* a recouper betty pas contente */