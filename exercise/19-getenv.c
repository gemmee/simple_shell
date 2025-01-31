#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define DELIM "="
extern char **environ;

/**
 * _getenv - gets an environment variable without using getenv
 * @name: the name of environment variable to be searched
 *
 * Return: a pointer to the corresponding value string
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *token, *copy, *value;
	
	while (environ[i])
	{
		copy = strdup(environ[i]); /* make a copy to avoid modifying `environ` */
		token = strtok(copy, DELIM);
		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, DELIM);
			value = token ? strdup(token) : NULL; /* copy value before freeing to avoid dangling pointer*/
			free(copy);
			return value;
		}
		free(copy);
		i++;
	}
	return (NULL);
}

/**
 * main - checks the usage of _getenv
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: %s ENV_VARIABLE\n", av[0]);
		return (1);
	}
	char *value = _getenv(av[1]);
	if (value)
	{
		printf("%s=%s\n", av[1], value);
		free(value); /* prevent memory leaks */
	}
	else
	{
		printf("%s not found\n", av[1]);
	}

	return (0);
}

