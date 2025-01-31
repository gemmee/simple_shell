#include <stdio.h>
#include <unistd.h>

extern char **environ;

/**
 * main - prints the address of env (the third parameter of the main function) and
 * environ (the global variable) to compare them
 *
 * Return: Always 0.
 * Author: Gamachu
 * Place: occ, Finfine
 */
int main(int ac, char **av, char **env)
{
	printf("Address of `env`: %p\n", env);
	printf("Address of `environ`: %p\n", environ);

	return (0);
}
