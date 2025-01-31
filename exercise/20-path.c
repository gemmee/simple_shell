#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

/**
 * main - prints each directory contained in the environment variable PATH,
 * one directory per line
 *
 * Return: Always 0.
 * Author: Gamachu
 * Place: occ, finfine
 */
int main()
{
	char *value = getenv("PATH");
	char *dir = strtok(value, ":");

	while (dir)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}

	return (0);
}
