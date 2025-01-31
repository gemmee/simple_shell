#include <unistd.h> /*for execve */
#include <stdio.h> /* for printf */
#include <stdlib.h> /*for EXIT_FAILURE*/

int main()
{
	/* Path to the compiled program */
	char *program = "./program_to_execute";

	/* Arguments to pass to the program */
	char *args[] = {program, "arg1", "arg2", NULL};

	/* Environment variables (optional, NULL for no special environment) */
	char *env[] = {NULL};

	printf("Before execve: Running the program...\n");

	/* Execute the program */
	if (execve(program, args, env) == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}

	/* This will not execute unless execve fails*/
	printf("After execve (this won't run if execve works)\n");

	return 0;
}
