# Simple Shell — holberton_simple_shell

A minimalist UNIX command interpreter written in C.  
This project reproduces the core behavior of `/bin/sh` and focuses on understanding how a shell truly works: processes, system calls, environment handling, and execution flow.

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

## Project Information

- **Project name:** Simple Shell  
- **Directory name:** `holberton_simple_shell`  
- **Binary name:** `hsh`  
- **Original repository:**  
  https://github.com/SaraEstelle/holbertonschool-simple_shell.git  

### Contributors

- **Alison Amblard**  
  GitHub: https://github.com/Ali731-Amb  

- **Sara Estelle Rebati**  
  GitHub: https://github.com/SaraEstelle  

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

## Learning Objectives

By the end of this project, you should be able to explain, without using Google:

- Who designed and implemented the original UNIX operating system  
- Who wrote the first version of the UNIX shell  
- Who invented the B programming language (direct predecessor of C)  
- Who Ken Thompson is  
- How a shell works internally  
- What a PID and a PPID are  
- How to manipulate the environment of the current process  
- The difference between a function and a system call  
- How to create processes  
- The three prototypes of `main`  
- How the shell uses `PATH` to find programs  
- How to execute a program using `execve`  
- How to suspend execution until a child process terminates  
- What EOF (End Of File) is  

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- Compilation environment: Ubuntu 20.04 LTS
- Compiler: `gcc`
- Compilation flags:  
  `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files must end with a new line
- A `README.md` file at the root of the project is mandatory
- Code must follow the **Betty** style  
  Checked using `betty-style.pl` and `betty-doc.pl`
- No memory leaks allowed
- Maximum of **5 functions per file**
- All header files must be include guarded
- Use system calls only when necessary
- One GitHub repository per group  
  Cloning or duplicating a repository before the second deadline may result in a **0% score**

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

## Output

Unless specified otherwise, the program must behave exactly like `/bin/sh`, including:

- Standard output
- Error output

The only difference:  
Error messages must use `argv[0]` as the program name.

### Example with `/bin/sh`

`echo "qwerty" | /bin/sh`  
`/bin/sh: 1: qwerty: not found`

`echo "qwerty" | /bin/../bin/sh`  
`/bin/../bin/sh: 1: qwerty: not found`

### Same example with `hsh`

`echo "qwerty" | ./hsh`  
`./hsh: 1: qwerty: not found`

`echo "qwerty" | ./././hsh`  
`./././hsh: 1: qwerty: not found`

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

## Allowed Functions and System Calls

### Standard Library
- All functions from `<string.h>`

### System Calls and Functions
- `access`
- `chdir`
- `close`
- `closedir`
- `execve`
- `exit`
- `_exit`
- `fflush`
- `fork`
- `free`
- `getcwd`
- `getline`
- `getpid`
- `isatty`
- `kill`
- `malloc`
- `open`
- `opendir`
- `perror`
- `printf`
- `fprintf`
- `vfprintf`
- `sprintf`
- `putchar`
- `read`
- `readdir`
- `signal`
- `stat`
- `lstat`
- `fstat`
- `strtok`
- `wait`
- `waitpid`
- `wait3`
- `wait4`
- `write`

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

## Compilation

The shell must be compiled using:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

## Usage

### Interactive Mode

`./hsh`  
`($) /bin/ls`  
`hsh main.c shell.c`  
`($) exit`

### Non-Interactive Mode

`echo "/bin/ls" | ./hsh`  
`hsh main.c shell.c test_ls_2`

`cat test_ls_2`  
`/bin/ls`  
`/bin/ls`

`cat test_ls_2 | ./hsh`  
`hsh main.c shell.c test_ls_2`  
`hsh main.c shell.c test_ls_2`

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

## Testing and Checker

- The checker will be released 1–2 days before the deadline
- Students are encouraged to collaborate on:
  - Standard tests
  - Edge cases
  - Stress tests
- After the deadline, the repository must be forked (if needed) for correction

━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

## Final Note

This project is about understanding, not shortcuts.  
Every system call exists for a reason.  
If you can explain *why* each one is used, then the shell is doing its job — and so are you.
