#include "simple_shell.h"

/**
 * main - Simple Shell v0.1
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment
 * Return: 0
 */
int main(int argc, char **argv, char **envp)
{
	char *line;
	char *args[64];
	char *cmd_path;
	pid_t pid;
	int status, arg_count;
	struct stat st;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		line = read_line();
		if (!line)
			break;

		/* Parse la ligne en arguments */
		arg_count = parse_args(line, args);
		arg_count++;
		if (arg_count == 0 || args[0] == NULL ||args[0][0] == '\0' )/*changement dernier condition*/
		{
			free(line);
			continue;
		}

		/* Si la commande contient '/', c'est un chemin direct */
		if (_strchr(args[0], '/') != NULL)
		{
			if (stat(args[0], &st) != 0)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
				free(line);
	/*rajout */ if(!isatty (STD))
				continue;
			}
			cmd_path = args[0];
		}
		else
		{
			/* Chercher dans PATH */
			cmd_path = _which(args[0], my_getenv("PATH", envp));
			if (cmd_path == NULL || cmd_path[0] == '\0')
			{
				fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
				free(line);
				exit(127);
			}
			/*voir pour le chemin path vide*/
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(cmd_path, args, envp) == -1)
			{
				perror(argv[0]);
				if (cmd_path != args[0])
					free(cmd_path);
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		else if (pid > 0)
		{
			wait(&status);
			if (cmd_path != args[0])
				free(cmd_path);
		}
		else
		{
			perror("fork");
			if (cmd_path != args[0])
				free(cmd_path);
		}

		free(line);
	}
	return (0);
}
/*prbleme de ligne a recouper */