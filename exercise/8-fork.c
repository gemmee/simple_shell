#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t pid;

	printf("Before fork\n");
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	printf("After fork\n");
	my_pid = getpid();
	if (pid == 0)
	{
		printf("I'm the child process as fork returns 0\n");
		printf("My pid is %u\n", my_pid);
	}
	else
	{
		printf("I'm the parent process as fork return PID of my child %u\n", pid);
		printf("My pid is %u\n", my_pid);
	}
	return (0);
}
