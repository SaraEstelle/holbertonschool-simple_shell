#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/**
 * simple_shell.h - Header file for the Simple Shell project
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

/* Environment */
extern char **environ;

/* String helper functions */
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strchr(char *s, char c);

/* Environment helper function */
char *my_getenv(const char *name, char **envp);

/**
 * struct simple_shell - Shell state structure
 * @is_interactive: interactive mode flag
 * @exit_status: last command exit status
 */
typedef struct simple_shell
{
	int is_interactive;
	int exit_status;
} simple_shell_t;

/* Shell core functions (to be implemented later) */
int parse_args(char *line, char **args);
void my_fork(char **args, char **argv, char **envp);
char *_which(const char *command, const char *path_env);
int exit_command(char *line);
int env_command(char **envp);
void run_shell(simple_shell_t *shell_state, char **argv, char **envp);
char *read_line(void);

#endif /* SIMPLE_SHELL_H */
