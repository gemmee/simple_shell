#include "simple_shell.h"


/**
 * main - main loop that parses input from command line interface
 * @argc: number of arguments to the program
 * @argv: array of arguments
 *
 * Return: Always 0 on success.
 */
int main(int argc, char *argv[])
{
	char *command = NULL, **tokenized_cmd = NULL;
	size_t size = 0;
	ssize_t retval = 0;
	(void)argc;

	while (1)
	{
		size = 0;
		if (isatty(1))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		retval = getline(&command, &size, stdin);

		/*Handle end of file (Ctrl + D) condition*/
		if (retval == -1 || retval == EOF)
		{
			free(command);
			return (retval);
		}
		/*tokenize command*/
		tokenized_cmd = tokenizer(command);
		if (tokenized_cmd[0] == NULL || !tokenized_cmd)
		{
			free(command);
			continue;
		}
		/*check if the first command is executable*/
		if (is_executable(tokenized_cmd[0]))
		{
			retval = execute_cmd(tokenized_cmd);
		}
		else
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
			retval = -1;
		}
		free(command);
		free(tokenized_cmd);
	}
	return (retval);
}

/**
 * tokenizer - tokenizes a command string
 * @cmd: the command string
 *
 * Return: a pointer to a pointer
 */
char **tokenizer(char *cmd)
{
	int idx = 0, size = 50;
	char **tokens = malloc(size * sizeof(char *));
	char *token;

	if (tokens == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (NULL);
	}
	token = strtok(cmd, " \n\t");
	while (token)
	{
		tokens[idx] = token;
		idx++;
		token = strtok(NULL, " \n\t");
	}
	tokens[idx] = NULL;
	return (tokens);
}

/**
 * is_executable - checks if the command is executable
 * @cmd: the command
 *
 * Return: 1 if it's executable, 0 otherwise
 */
int is_executable(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (1);
	else
		return (0);
}

/**
 * execute_cmd - executes command
 * @tok_cmd: tokenized command
 *
 * Return: Nothing on success, -1 on failure
 */
int execute_cmd(char **tok_cmd)
{
	pid_t pid;
	int status, retval = 0;

	pid = fork();
	if (pid < 0)
	{
		fprintf(stderr, "Forking failed\n");
		retval = -1;
	}
	else if (pid == 0)
	{
		execve(tok_cmd[0], tok_cmd, environ);
		fprintf(stderr, "Cannot execute the file\n");
		retval = -1;
	}
	else
	{
		wait(&status);
	}
	return (retval);
}
