#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	/* Attempt to open a non-existent file */
	int fd = open("non_existent_file.txt", O_RDONLY);

	if (fd == -1)
	{
		/* print a custom message along with the system error */
		perror("Error opening file");
	}

	/* Attempt to close an invalid file descriptor */
	int result = close(-1);
	if (result == -1)
	{
		/* Print a custom message along with the system error */
		perror("Error closing file descriptor");
	}

	return 0;
}
