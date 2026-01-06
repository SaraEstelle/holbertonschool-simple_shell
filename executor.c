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

	if (args == NULL || args[0] == NULL)
		return;

	cmd_path = _which(args[0], my_getenv("PATH", envp));
	if (cmd_path == NULL)
	{
		fprintf(stderr, "Shell :%s No such file or directory\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(cmd_path);
		return;
	}

	if (pid == 0)
	{
		if (execve(cmd_path, args, envp) == -1)
		{
			perror(argv[0]);
			free(cmd_path);
			exit(1);
		}
	}
	else
	{
		wait(&status);
		free(cmd_path);
	}
}
