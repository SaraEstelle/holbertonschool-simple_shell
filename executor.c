#include "simple_shell.h"

/**
 * get_cmd_path - determine command path
 * @args: argument array
 * @envp: environment variables
 * @argv: program name
 * @cmd_count: command counter
 * @should_free: flag to know if path must be freed
 *
 * Return: command path or NULL
 */
char *get_cmd_path(char **args, char **envp, char **argv,
				   int cmd_count, int *should_free)
{
	char *cmd_path = NULL;
	char *path_env;

	*should_free = 0;

	if (_strchr(args[0], '/'))
	{
		if (access(args[0], X_OK) == 0)
			return (args[0]);

		fprintf(stderr, "%s: %d: %s: not found\n",
				argv[0], cmd_count, args[0]);
		return (NULL);
	}

	path_env = my_getenv("PATH", envp);
	if (path_env && path_env[0] != '\0')
	{
		cmd_path = _which(args[0], path_env);
		if (cmd_path)
			*should_free = 1;
	}

	if (!cmd_path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
				argv[0], cmd_count, args[0]);
		return (NULL);
	}

	return (cmd_path);
}

/**
 * execute_child - execute command in child process
 * @cmd_path: command path
 * @args: arguments
 * @envp: environment
 * @argv: program name
 * @cmd_count: command counter
 * @should_free: free flag
 */
void execute_child(char *cmd_path, char **args, char **envp,
				   char **argv, int cmd_count, int should_free)
{
	if (execve(cmd_path, args, envp) == -1)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
				argv[0], cmd_count, args[0]);
		if (should_free)
			free(cmd_path);
		exit(127);
	}
}

/**
 * execute_parent - wait for child
 * @pid: child pid
 * @cmd_path: command path
 * @should_free: free flag
 *
 * Return: exit status
 */
int execute_parent(pid_t pid, char *cmd_path, int should_free)
{
	int status;
	(void)pid;

	wait(&status);

	if (should_free && cmd_path)
		free(cmd_path);

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (0);
}

/**
 * my_fork - Creates a child process and executes a command
 * @args: argument array
 * @argv: program name
 * @envp: environment variables
 * @cmd_count: command counter for error messages
 *
 * Return: exit status of the command
 */
int my_fork(char **args, char **argv, char **envp, int cmd_count)
{
	pid_t pid;
	char *cmd_path;
	int should_free;

	if (!args || !args[0])
		return (0);

	cmd_path = get_cmd_path(args, envp, argv, cmd_count, &should_free);
	if (!cmd_path)
		return (127);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		if (should_free)
			free(cmd_path);
		return (1);
	}

	if (pid == 0)
		execute_child(cmd_path, args, envp,
					  argv, cmd_count, should_free);

	return (execute_parent(pid, cmd_path, should_free));
}
