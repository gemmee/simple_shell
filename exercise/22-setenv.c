#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

/**
 * _setenv - changes or adds an environment variable
 * @name: name of the variable
 * @value: value of the variable
 * @overwrite: If 0, does not change existing variable
 *
 * Return: 0 on success, -1 on failure
 */
 int _setenv(const char *name, const char *value, int overwrite)
{
	int i;
	size_t name_len = strlen(name);
	size_t value_len = strlen(value);
	char *new_var;

	/* check for invalid input */
	if (!name || !value || strchr(name, '='))
		return (-1);

	/* search if the variable exists */
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			/* If overwrite is 0, do not change existing variable */
			if (!overwrite)
				return (0);

			/* Replace existing variable */
			new_var = malloc(name_len + value_len + 2);
			if (!new_var)
				return (-1);

			sprintf(new_var, "%s=%s", name, value);
			environ[i] = new_var; /* directly modify the environment */
			return (0);

		}
	
	}

	/* Add a new variable if not found */
	new_var = malloc(name_len + value_len + 2);
	if (!new_var)
		return (-1);

	sprintf(new_var, "%s=%s", name, value);

	/* Extend environ by adding new_var */
	environ[i] = new_var;
	environ[i + 1] = NULL;

	return (0);
}

/* main function to test _setenv */
int main(void)
{
	printf("Before _setenv: MY_VAR=%s\n", getenv("MY_VAR"));
	_setenv("MY_VAR", "Hello, Gamachu!", 1);
	printf("After _setenv: MY_VAR=%s\n", getenv("MY_VAR"));

	return (0);
}
