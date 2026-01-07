#include "simple_shell.h"

/**
 * main - Simple Shell v0.1
 * @argc: argument count (unused)
 * @argv: argument vector
 * @envp: environment variables
 *
 * Return: Always 0
 */
int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	char *args[2];
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;
	struct stat st;

	(void)argc;

	while (1)
	{
		/* Display prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		/* Read input */
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			break;
		}

		/* Remove trailing newline */
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		/* Ignore empty input */
		if (line[0] == '\0')
			continue;

		/* v0.1: only ONE command, NO arguments */
		args[0] = line;
		args[1] = NULL;

		/* Check if executable exists */
		if (stat(args[0], &st) != 0)
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
			continue;
		}

		/* Create child process */
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			continue;
		}

		if (pid == 0)
		{
			/* Child process */
			if (execve(args[0], args, envp) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process */
			wait(&status);
		}
	}

	return (0);
}
