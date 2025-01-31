#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - executes the command `ls -l /tmp` in 5 different
 * child processes. Each child should be created by the same
 * process(the father). It waits for a child to exit before creating a new child.
 *
 * Return: Nothing on success, -1 on error
 */
int main()
{
	char* argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t pid;
	int wstatus, i;

	i = 1;
	while (i <= 5)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Forking failed");
			return (-1);
		}
		if (pid == 0)
		{
			printf("\n\n");
			printf("I'm child %d\n", i);
			printf("------------\n\n");
			if (execve(argv[0], argv, NULL) == -1)
			{	
				perror("Error:");
				return (-1);
			}
			printf("After execve\n");
		}
		else
		{
			wait(&wstatus);
			if (i == 5)
				printf("\n\nFinally, here I'm - their Dad!\n");
		}
		i++;
	}

	return (0);
}
