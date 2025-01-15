#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the PID of the parent of calling process
 * prints the same value as `echo $$`
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_ppid;

	my_ppid = getppid();
	printf("%u\n", my_ppid);
	return (0);
}
