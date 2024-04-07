#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>


/**
 * struct builtin - builtin commands struct
 * @name: name of builtin command
 * @func: pointer to builtin command functions
 *
 */
typedef struct builtin
{
	char *name;
	int (*func)(char **, char *, int *);
} builtins_t;

/*global variable to access the environment list*/
extern char **environ;

char **tokenizer(char *cmd);
int is_executable(char *cmd);
int execute_cmd(char **tok_cmd);

#endif
