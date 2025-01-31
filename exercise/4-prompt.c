#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *line = NULL; /*pointer to hold the input line*/
	size_t len = 0; /*size of the buffer for getline*/
	ssize_t nread; /*number of characters read by getline*/

	while (1)
	{
		printf("$ "); /*Display the prompt*/
		fflush(stdout); /*Ensure the prompt is displayed immediately*/

		/*Read a line from the user*/
		nread = getline(&line, &len, stdin);

		/*Check if getline encountered EOF or an error*/
		if (nread == -1)
		{
			printf("\n");
			break; /*Exit the loop on EOF*/
		}

		/*Print the entered command (line)*/
		printf("%s", line);
	}
	free(line);
	return 0;
}
