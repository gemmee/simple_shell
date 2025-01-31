#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *cwd = (char *)malloc(1024);
	if (cwd == NULL)
	{
		perror("malloc");
		return 1;
	}

	/* print the current working directory */
	if (getcwd(cwd, 1024) == NULL)
	{
		perror("getcwd");
		free(cwd);
		return 1;
	}
	printf("Current working directory: %s\n", cwd);

	/* change the working directory */
	if (chdir("../") != 0)
	{
		perror("chdir");
		free(cwd);
		return 1;
	}

	/* verify the change */
	if (getcwd(cwd, 1024) == NULL)
	{
		perror("getcwd");
		free(cwd);
		return 1;
	}
	printf("New working directory: %s\n", cwd);
	free(cwd);
	return 0;
}
