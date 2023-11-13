#include "shell.h"

/**
 * _strlen - function
 *
 * Description: function that returns the length of a string.
 *
 * @s: input
 *
 * Return: 0 always
*/

int _strlen(char *s)
{
	int len = strlen(s);

	return (len);
}

/**
 * _strcmp - function
 *
 * Description: function that compares two strings
 *
 * @s1: input
 * @s2: input
 *
 * Return: result
*/

int _strcmp(char *s1, char *s2)
{
	int result;

	result = strcmp(s1, s2);
	return (result);
}

/**
 * _strcat - function
 *
 * Description: function that concatenates two strings
 *
 * @dest: input
 * @src: input
 *
 * Return: 0
*/

char *_strcat(char *dest, char *src)
{
	strcat(dest, src);
	return (dest);
}
