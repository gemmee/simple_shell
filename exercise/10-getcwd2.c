#include <stdio.h>
#include <unistd.h>

int main()
{
	char cwd[1024]; /* fixed buffer size*/
	/* char cwd[10]; /* not enough size buffer*/

	/* get the current working directory*/
	if (getcwd(cwd, sizeof cwd) == NULL)
	{
		perror("getcwd");
		return 1;
	}
	/* print the current working directory*/
	printf("Current working directory: %s\n", cwd);

	return 0;
}
