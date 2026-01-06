# Simple Shell

## Description

**Simple Shell** is a UNIX command line interpreter written in C.  
It is a minimalist implementation of `/bin/sh`, developed as part of the Holberton School curriculum to understand how a shell works internally.

The shell reads user input, parses command lines, executes programs using system calls, and handles both interactive and non-interactive modes while respecting strict coding and system constraints.

---

## Features

The project evolves progressively through several versions.

### Simple Shell 0.1
- Display a prompt and wait for user input
- Execute commands without arguments
- Do not use the `PATH`
- Handle errors when a command cannot be found
- Handle end-of-file condition (Ctrl + D)
- Work in both interactive and non-interactive modes

### Simple Shell 0.2
- Handle command lines with arguments

### Simple Shell 0.3
- Handle the `PATH` environment variable
- Do not call `fork` if the command does not exist

### Simple Shell 0.4
- Implement the `exit` built-in command

### Simple Shell 1.0
- Implement the `env` built-in command to print the environment

---

## Requirements

### General
- Allowed editors: vi, vim, emacs
- Compiled on Ubuntu 20.04 LTS
- Compiler: gcc
- Compilation flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- All files must end with a new line
- A README.md file at the root of the project is mandatory
- Code must follow Betty style
- No memory leaks
- No more than 5 functions per file
- All header files must be include-guarded
- Use system calls only when necessary
- One GitHub repository per group

---

## Allowed Functions and System Calls

All functions from string.h  
access, chdir, close, closedir  
execve, exit, _exit  
fflush  
fork  
free  
getcwd, getline, getpid  
isatty  
kill  
malloc  
open, opendir  
perror  
printf, fprintf, vfprintf, sprintf  
putchar  
read  
readdir  
signal  
stat, lstat, fstat  
strtok  
wait, waitpid, wait3, wait4  
write  

---

## Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

---

## Usage

### Interactive Mode

$ ./hsh  
($) /bin/ls  
hsh main.c shell.c  
($) exit  

### Non-Interactive Mode

$ echo "/bin/ls" | ./hsh  
hsh main.c shell.c  

$ cat test_file | ./hsh  
hsh main.c shell.c test_file  

---

## Error Handling

Unless specified otherwise, the shell output must match /bin/sh.  
The only difference is when printing errors: the program name must be equivalent to argv[0].

Example:

$ echo "qwerty" | ./hsh  
./hsh: 1: qwerty: not found  

---

## Built-in Commands

exit  
Exits the shell.

env  
Prints the current environment.

---

## Constraints and Limitations

- No semicolons
- No pipes
- No redirections
- No cursor movement
- No special characters: ", ', `, \, *, &, #
- No advanced shell features
- Environment must be passed explicitly to execve

---

## Repository

GitHub repository: holbertonschool-simple_shell

---

## Auteurs
- AMBLARD Alison — `@Ali731-Amb`  
- REBATI Estelle Sara — @SaraEstelle

---

## Licence
Projet interne — Holberton School / ALX  
Usage pédagogique uniquement.
