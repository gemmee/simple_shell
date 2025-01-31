#include <unistd.h>
#include <stdio.h>

int main()
{
	char *args[] = {"/bin/echo", "Hello from execve!", NULL}; /* Program and arguments */
	char *env[] = {NULL}; /* Environment variables */

	printf("Before execve\n");

	/* Replace current process with /bin/echo */
	if (execve("/bin/echo", args, env) == -1)
	{
		perror("execve failed");
	}

	/* This line will not be executed if execve succeeds */
	printf("After execve (this won't run if execve works)\n");

	return 0;
}
