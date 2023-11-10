This us again for the second time trying to pass simple shell. please please

first of all we will add the header file with the most common libraries.

# Steps of building a shell in C language:

**Read Input: Use fgets or a similar function to read input from the user.**

**Parse Input: Tokenize the input to separate the command and its arguments. You can use strtok or similar functions.**

**Fork a Child Process: Use fork to create a child process that will execute the command.**

**Execute Commands: In the child process, use exec functions (like execl, execvp, etc.) to run the specified command with its arguments.**

**Wait for Child: In the parent process, use wait or waitpid to wait for the child process to finish.**

**Handling Built-in Commands: Implement any built-in commands like "cd" or "exit" in your shell separately in your C code.**

---