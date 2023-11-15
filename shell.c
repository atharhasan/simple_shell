#include "shell.h"

/**
 * handle_env - function that handle env
 * @env2: Another array of strings for "env" command
 */
void handle_env(char **env2)
{
	while (*env2)
	{
		write(STDOUT_FILENO, *env2, _strlen(*env2));
		write(STDOUT_FILENO, "\n", 1);
		env2++;
	}
}

/**
 * main - shell main file
 * @argc: The number of command-line arguments but it's not used
 * @env: an array of strings
 * @env2: Another array of strings for "env" command
 * Return: value
 */
int main(int argc, char **env, char **env2)
{
	char *command = NULL, *token, *args[512];
	int argCount = 0, i, value = 0, error_count = 0, linval;
	size_t len = 0;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		linval = getline(&command, &len, stdin);
		if (linval == -1)
			break;
		error_count++;
		command[strcspn(command, "\n")] = '\0';
		token = strtok(command, " ");
		while (token != NULL)
		{
			args[argCount++] = token;
			token = strtok(NULL, " ");
		}
		args[argCount] = NULL;
		if (argCount > 0)
		{
			if (_strcmp(args[0], "exit") == 0)
				break;
			if (_strcmp(args[0], "env") == 0)
			{
				handle_env(env2);
				continue;
			}
			value = cd_handle(args, env, argCount, error_count);
		}
		for (i = 0; i < 512; i++)
			args[i] = NULL;
		argCount = 0;
	}
	free(command);
	return (value);
}
