#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
		return 1;
	}

	const char *file_path = argv[1];
	/* Check if the file exists */
	if (access(file_path, F_OK) == 0)
	{
		printf("File '%s' exists.\n", file_path);
		/* check read permission */
		if (access(file_path, R_OK) == 0)
		{
			printf("You have read permission on '%s'.\n", file_path);
		}
		else
		{
			perror("Read permission check failed");
		}

		/* check write permission */
		if (access(file_path, W_OK) == 0)
		{
			printf("You have write permission on '%s'.\n", file_path);
		}
		else
		{
			perror("Write permission check failed");
		}

		/* check execute permission */
		if (access(file_path, X_OK) == 0)
		{
			printf("You have execute permission on '%s'.\n", file_path);
		}
		else
		{
			perror("Execute permission check failed");
		}
	}
	else
	{
		perror("File existence check failed");
	}

	return 0;
}
