#include "shell.h"

/**
 * find_executable - function
 * @command: The command string to execute.
 * Return: 0
 */

char *find_executable(char *command)
{
	char full_env[1024];
	char *env_copy;
	char *token;

	char *env = getenv("PATH");

	env_copy = strdup(env);

	if (env_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	token = strtok(env_copy, ":");

	while (token != NULL)
	{
		strcpy(full_env, token);
		_strcat(full_env, "/");
		_strcat(full_env, command);

		if (access(full_env, X_OK) == 0)
		{
			free(env_copy);
			return (strdup(full_env));
		}
		token = strtok(NULL, ":");
	}
	free(env_copy);
	return (NULL);
}
