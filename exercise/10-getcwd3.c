#include <stdio.h> /* printf */
#include <unistd.h> /* getcwd */
#include <stdlib.h> /* free */

int main()
{
	/* dynamically allocate the buffer*/
	char *cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
		perror("getcwd");
		return 1;
	}
	/* print the current working directory*/
	printf("Current working directory: %s\n", cwd);

	/* free the allocated memory*/
	free(cwd);
	return 0;
}
