#include "shell.h"

/**
 * check_strcmp - Handle special cases
 * @args: Array of arguments
 * @env: Environmental variables
 * @prev_dir: Previous directory
 * @error_count: Error count
*/

void check_strcmp(char *args[], char **env, char *prev_dir, int error_count)
{
	char cwd[100];

	if (_strcmp(args[1], "-") == 0)
	{
		if (prev_dir != NULL)
		{
			if (chdir(prev_dir) != 0)
				perror("perror");
			else
			{
				if (getcwd(cwd, sizeof(cwd)) != NULL)
				{
					write(STDOUT_FILENO, cwd, _strlen(cwd));
					write(STDOUT_FILENO, "\n", 1);
				}
			}
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
			fprintf(stderr, "%s: %d: %s: can't cd to %s\n", env[0],
					error_count, args[0], args[1]);
	}
}

/**
 * cd_handle - a function that Changes the directory
 * @args: Array of arguments
 * @env: Environmental variables
 * @argCount: Number of arguments
 * @error_count: Error count for error reporting
 *
 * Return: Exit value
*/
int cd_handle(char *args[], char **env, int argCount, int error_count)
{
	char *home = getenv("HOME"), *prev_dir = getenv("OLDPWD");
	int value = 0;

	if (_strcmp(args[0], "cd") == 0)
	{
		if (argCount > 1)
		{
			check_strcmp(args, env, prev_dir, error_count);
		}
		else
		{
			if (home != NULL)
			{
				if (chdir(home) != 0)
					perror("cd error");
			}
		}
	}
	else
		value = fork_fun(args, env, error_count);
	return (value);
}
