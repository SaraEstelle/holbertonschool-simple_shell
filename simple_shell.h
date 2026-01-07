#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>

/* External Variables "Environment" */
extern char **environ;

/* Main Shell Structure */
/**
 * struct simple_shell - Shell state structure
 * @is_interactive: interactive mode flag
 * @exit_status: last command exit status
 * @cmd_count: command counter for error messages
 */
typedef struct simple_shell
{
	int is_interactive;
	int exit_status;
	int cmd_count;
} simple_shell_t;

/* String helper functions */
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(char *s, char c);

/* Environment helper function */
char *my_getenv(const char *name, char **envp);
int _printenv(char **envp);

/* Shell core functions */
int parse_args(char *line, char **args);
int my_fork(char **args, char **argv, char **envp, int cmd_count);
char *_which(const char *command, const char *path_env);
int exit_command(char *line);
int env_command(char **envp);
void run_shell(simple_shell_t *shell_state, char **argv, char **envp);
char *read_line(void);

#endif /* SIMPLE_SHELL_H */
