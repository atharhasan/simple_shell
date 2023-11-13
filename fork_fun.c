#include "shell.h"

/**
 * fork_fun - forking and executing a command
 * @args: Arguments for the command
 * @env: Environmental variables
 * @error_count: Error count
 * Return: Exit value
 */
int fork_fun(char *args[], char **env, int error_count)
{
	pid_t pid;
	int value = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		char *order = NULL;

		if (args[0][0] != '/')
			order = find_executable(args[0]);
		if (order == NULL)
			order = args[0];
		if (execve(order, args, env) == -1)
		{
			value = 127;
		}
		fprintf(stderr, "%s: %d: %s: not found\n", env[0], error_count, args[0]);
		exit(127);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			value = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			value = WTERMSIG(status);
		else
		{
			perror("Wait failed");
		}
	}
	return (value);
}
