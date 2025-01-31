#include <stdio.h>

/**
 * main - prints all the command line arguments
 * without using ac
 *
 * @ac: the number of items in av
 * @av: a NULL terminated array of strings
 *
 * Return: Always 0.
 * Author: Gamachu
 * Place: occ, Finfine
 */
int main(int ac, char **av)
{
	(void)ac;
	int i;

	/* av[0] contains the name used to invoke the current program */
	for (i = 1; av[i] != NULL; i++)
		printf("%s\n", av[i]);

}
