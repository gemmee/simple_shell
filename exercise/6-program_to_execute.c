#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("Hello from program_to_execute!\n");

	/* Optionally, print any arguments passed */
	for (int i = 0; i < argc; i++)
	{
		printf("Argument %d: %s\n", i, argv[i]);
	}

	return 0;
}
