#include "simple_shell.h"

/**
 *
 *
 */

void run_shell(simple_shell_t *shell_state, char **argv, char **envp)
{
    char *line;
    char *args[2]; /* Pour la v0.1 : commande + NULL */

    while (1)
    {
        if (shell_state->is_interactive)
            write(1, "#cisfun$ ", 9);

        line = read_line(); /* Étape 3 de ton plan */
        if (!line) /* Gestion du Ctrl+D */
            break;

        if (parse_args(line, args) == 0) /* Étape 5 & 6 : Nettoyage et préparation */
        {
            my_fork(args, argv, envp); /* Étape 7, 8 & 9 : Fork, Exec, Wait */
        }
        
        free(line); /* On libère SEULEMENT ici, après l'exécution */
    }
}
