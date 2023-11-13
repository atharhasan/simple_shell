This us again for the second time trying to pass simple shell. please please

first of all we will add the header file with the most common libraries.

# Steps of building a shell in C language:

**Read Input: Use fgets or a similar function to read input from the user.**

**Parse Input: Tokenize the input to separate the command and its arguments. You can use strtok or similar functions.**

**Fork a Child Process: Use fork to create a child process that will execute the command.**

**Execute Commands: In the child process, use exec functions (like execl, execve, etc.) to run the specified command with its arguments.**

**Wait for Child: In the parent process, use wait or waitpid to wait for the child process to finish.**

**Handling Built-in Commands: Implement any built-in commands like "cd" or "exit" in your shell separately in your C code.**
---

### 0. Betty would be proud
_*mandatory*_
Write a beautiful code that passes the Betty checks
---

### 1. Simple shell 0.1
_*mandatory*_
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments
execve will be the core part of your Shell, don’t forget to pass the environ to it…
---

### 2. Simple shell 0.2
_*mandatory*_
- Simple shell 0.1 +

Handle command lines with arguments
---

### 3. Simple shell 0.3
_*mandatory*_
Simple shell 0.2 +

Handle the PATH
fork must not be called if the command doesn’t exist
---

### 4. Simple shell 0.4
_*mandatory*_
Simple shell 0.3 +

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit
---

### 5. Simple shell 1.0
_*mandatory*_
Simple shell 0.4 +

Implement the env built-in, that prints the current environment
---

### With some ADVANCED Tasks
- Everything tested and working very well after very hard working on this project in a test repo


Best Regards;
*Athar Hasan & Mohammad Elkhiat*