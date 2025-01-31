#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * _unsetenv - deletes the variable name from the environment without
 *  using `unsetenv' lib function
 *  @name: the name env variable to be deleted
 *
 *  Return: 0 on success and -1 on error.
 */
int _unsetenv(const char *name)
{
	if (name == NULL || *name == '\0' || strchr(name, '=') != NULL)
	{
		return (-1); /* Invalid input */
	}

	size_t name_len = strlen(name);
	char **env = environ;
	char **dst = environ;

	while (*env)
	{
		/*check if the current env variable matches the name */
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			/* skip this variable (remove it) */
			env++;
			continue;
		}
		/* keep this variable in the modified environment */
		*dst++ = *env++;
	}
	*dst = NULL; /* NULL-terminate the modified environment */
	return (0);
}


/**
 * main - tests the _unsetenv function
 *
 */
int main(void)
{
	setenv("MY_VAR", "Chala", 0); 
	printf("Before unset: %s\n", getenv("MY_VAR"));
	_unsetenv("MY_VAR");
	printf("After unset: %s\n", getenv("MY_VAR"));
	return (0);
}
