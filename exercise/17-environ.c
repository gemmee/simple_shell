#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>


/**
 * main - prints the environment using the global variable environ.
 *
 * Return: Always 0.
 * Author: Gamachu
 * Place: occ
 */
int main()
{
	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
	return (0);
}
