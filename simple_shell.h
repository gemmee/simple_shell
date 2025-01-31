#ifndef _SIMPLE_SHELL_
#define _SIMPLE_SHELL_

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct InputBuffer - structure to hold input buffer details
 * @len: length of the buffer
 * @buf: pointer to the buffer
 */
typedef struct InputBuffer
{
	size_t len;
	char *buf;
} InputBuffer;

void display_prompt(void);

#endif
