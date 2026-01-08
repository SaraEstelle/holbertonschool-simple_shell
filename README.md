<img width="1408" height="768" alt="Gemini_Generated_Image_kvc90pkvc90pkvc9" src="https://github.com/user-attachments/assets/cb0e8e99-51e2-4fed-93b1-488f4965a166" />

# Simple Shell

![C](https://img.shields.io/badge/language-C-blue.svg)
![Shell](https://img.shields.io/badge/shell-bash-green.svg)
![Standard](https://img.shields.io/badge/standard-GNU89-orange.svg)

A simple UNIX command line interpreter built in C as part of the Holberton School curriculum.

## 📝 Description

**simple_shell** is a minimal educational UNIX shell that mimics basic functionalities of `sh`. It reads commands from standard input, parses them into arguments, and executes them by creating child processes. The shell supports both interactive and non-interactive modes, making it suitable for learning fundamental concepts of process management, system calls, and UNIX programming.

## ✨ Features

- ✅ Execute commands from `PATH` environment variable
- ✅ Execute commands with absolute or relative paths
- ✅ Support for command arguments
- ✅ Built-in commands: `exit`, `env`
- ✅ Interactive and non-interactive modes
- ✅ Proper error handling and exit status codes
- ✅ Command path resolution with `_which` function
- ✅ EOF (Ctrl+D) handling
- ✅ Memory leak prevention

## 🏗️ Project Structure

```
/holbertonschool-simple_shell
├── main.c                    # Entry point of the shell
├── simple_shell.h            # Header file with prototypes and structures
├── simple_shell_v1.0.c       # Main shell loop (run_shell function)
├── executor.c                # Command execution (fork, exec, wait)
├── parser.c                  # Command line parsing and tokenization
├── builtins.c                # Built-in commands implementation
├── _which.c                  # PATH resolution function
├── getline.c                 # Custom getline implementation
├── env_functions.c           # Environment variable functions
├── string_helper.c           # String manipulation utilities
├── man_simple_shell.1        # Manual page
├── AUTHORS                   # List of contributors
├── tests/                    # Test scripts and files
├── flowchart/                # Project flowcharts
└── illustrations/            # Project documentation images
```

## 🔧 Compilation

Compile all `.c` files with the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

### Compilation Flags Explained:
- `-Wall`: Enable all warnings
- `-Werror`: Treat warnings as errors
- `-Wextra`: Enable extra warnings
- `-pedantic`: Strict ISO C compliance
- `-std=gnu89`: Use GNU89 C standard

## 🚀 Usage

### Interactive Mode

Run the shell and enter commands at the prompt:

```bash
$ ./hsh
($) ls
AUTHORS  builtins.c  env_functions.c  executor.c  getline.c  main.c
($) pwd
/home/alison_unix/holbertonschool-simple_shell
($) /bin/echo "Hello, World!"
Hello, World!
($) exit
$
```

### Non-Interactive Mode

Pipe commands directly to the shell:

```bash
$ echo "ls -l" | ./hsh
total 120
-rw-r--r-- 1 user user  1234 Jan 07 2026 main.c
-rw-r--r-- 1 user user  2345 Jan 07 2026 executor.c
...

Using a file as input:

```bash
$ cat commands.txt
ls
pwd
env

$ cat commands.txt | ./hsh
```

## 🔨 Built-in Commands

| Command | Description | Usage |
|---------|-------------|-------|
| `exit` | Exit the shell | `($) exit` |
| `env` | Print environment variables | `($) env` |

## 🔍 How It Works

The shell operates in a continuous loop performing these steps:

1. **Prompt Display**: Shows `($) ` when in interactive mode
2. **Input Reading**: Reads a line using `getline()`
3. **Parsing**: Tokenizes the input into arguments using `strtok()`
4. **Builtin Check**: Determines if the command is a builtin
5. **Path Resolution**: Searches for the command in `PATH` directories
6. **Execution**: Forks a child process and executes with `execve()`
7. **Waiting**: Parent waits for child process to complete
8. **Repeat**: Returns to step 1

### Command Search Algorithm

1. If the command contains a `/`, it's treated as an absolute/relative path
2. Otherwise, search each directory in `PATH`:
   - Build candidate path: `directory/command`
   - Check existence with `stat()`
   - Execute if found
3. If not found, print error message to stderr

## 📚 System Calls Used

- `fork()` - Create a new process
- `execve()` - Execute a program
- `wait()` / `waitpid()` - Wait for child process
- `stat()` - Check file existence
- `getline()` - Read input line
- `isatty()` - Check if stdin is a terminal
- `write()` - Output to stdout/stderr

## 📖 Manual Page

View the manual page:

```bash
man ./man_simple_shell.1
```

## 🧪 Testing

### Basic Tests

```bash
# Test simple command
echo "ls" | ./hsh

# Test command with arguments
echo "ls -l /tmp" | ./hsh

# Test absolute path
echo "/bin/pwd" | ./hsh

# Test builtin
echo "env" | ./hsh

# Test exit
echo "exit" | ./hsh
```

### Comparison with sh

```bash
# Compare output with sh
echo "ls" | ./hsh > hsh_output.txt
echo "ls" | sh > sh_output.txt
diff hsh_output.txt sh_output.txt
```

## ⚠️ Known Limitations

- No support for quotes, escape characters, or comments
- No pipes (`|`), redirections (`>`, `<`), or logical operators (`&&`, `||`)
- Basic tokenization using spaces only (no multiple delimiters)
- Limited number of builtins
- No job control or signal handling
- No command history or tab completion
- No alias support
- No variable expansion (`$VAR`)

## 🎓 Learning Objectives

This project helps understand:

- How a shell works under the hood
- Process creation and management (`fork`, `exec`, `wait`)
- Environment variables and their manipulation
- System calls and their usage
- Memory management and leak prevention
- String parsing and manipulation
- Error handling in system programming
- The difference between library functions and system calls

## 📋 Requirements

- Ubuntu 20.04 LTS or similar Linux distribution
- GCC compiler with GNU89 standard support
- Basic understanding of C programming
- Knowledge of UNIX/Linux command line

## 👥 Authors

- **Sara Rebati** - [12152@holbertonstudent.com](mailto:12152@holbertonstudent.com)
- **Alison Amblard** - [12252@holbertonstudents.com](mailto:12252@holbertonstudents.com)

## 📄 License

This project is part of the Holberton School curriculum and is intended for educational purposes.

## 🙏 Acknowledgments

- Holberton School for the project guidelines
- The creators of the original UNIX shell
- All contributors and testers

## 📚 References

- [Unix Shell Wikipedia](https://en.wikipedia.org/wiki/Unix_shell)
- [fork(2) man page](https://man7.org/linux/man-pages/man2/fork.2.html)
- [execve(2) man page](https://man7.org/linux/man-pages/man2/execve.2.html)
- [wait(2) man page](https://man7.org/linux/man-pages/man2/wait.2.html)

---

*Last updated: January 2026*
