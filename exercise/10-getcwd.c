#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *cwd;
	size_t size = 1024;

	/* allocate memory for the buffer*/
	cwd = (char *)malloc(size);
	if (cwd == NULL)
	{
		perror("malloc");
		return 1;
	}
	/* get the current working directory*/
	if (getcwd(cwd, size) == NULL)
	{
		perror("getcwd");
		free(cwd); /* free the allocated memory*/
		return 1;
	}
	/* print the current working directory*/
	printf("Current working directory: %s\n", cwd);

	/* free the allocated memory*/
	free(cwd);
	return 0;
}
