#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 64

extern char **environ;

char *find_executable(char* command);
int fork_fun(char *args[], char **env, int error_count);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int cd_handle(char *args[], char **env, int argCount, int error_count);
void check_strcmp (char *args[], char **env, char *prev_dir, int error_count);
void handle_env(char **env2);
ssize_t _getline(char **line, size_t *n, FILE *stream);

#endif
