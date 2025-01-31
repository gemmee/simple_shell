#include "simple_shell.h"

#define PROMPT "#cisfun$ "

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on success.
 */
int main(void)
{
	int wstatus;
	char *cmd;
	ssize_t nread;
	char *argv[2];
	InputBuffer input = {0, NULL};

	while (1)
	{
		display_prompt();
		nread = getline(&input.buf, &input.len, stdin);

		if (nread == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		input.buf[nread - 1] = '\0';
		cmd = input.buf;

		if (strlen(cmd) == 0)
			continue;

		if (fork() == 0)
		{
			argv[0] = cmd;
			argv[1] = NULL;
			execve(cmd, argv, environ);
			perror("./shell");
			exit(1);
		}

		wait(&wstatus);
	}
	free(input.buf);
	return (0);
}


/**
 * display_prompt - prints the shell prompt to stdout
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
}
