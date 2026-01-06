#include "simple_shell.h"

int main(int argc, char **argv, char **envp)
{
	simple_shell_t shell_state;
	
	(void)argc;
	shell_state.is_interactive = isatty(STDIN_FILENO);
	
	run_shell(&shell_state, argv, envp);
	
	return (0);
}
