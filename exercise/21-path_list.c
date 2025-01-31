#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DELIM ":"

extern char **environ;


/* Linked list node structure */
typedef struct path_node
{
	char *dir;
	struct path_node *next;
} path_node_t;

/**
 * add_node_end - Adds a new node to the end of the linked list
 * @head: pointer to the head of the list
 * @dir: directory path to store
 *
 * Return: pointer to the new node
 */
path_node_t *add_node_end(path_node_t **head, char *dir)
{
	path_node_t *new_node = malloc(sizeof(path_node_t));
	path_node_t *temp = *head;

	if (!new_node)
		return (NULL);

	new_node->dir = strdup(dir);
	if (!new_node->dir)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}

	return (new_node);
}



/**
 * build_path_list - parses PATH and builds a linked list of directories
 *
 * Return: pointer to the head of the linked list
 * Author: Gamachu
 * Place: occ, finfine
 */
path_node_t *build_path_list()
{
	char *path = getenv("PATH");
	if (!path)
		return (NULL);

	path_node_t *head = NULL;
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, DELIM);

	while (token)
	{
		add_node_end(&head, token);
		token = strtok(NULL, DELIM);
	}

	free(path_copy);
	return head;
}

/**
 * print_path_list - prints the linked list
 */
void print_path_list(path_node_t *head)
{
	while (head)
	{
		printf("%s\n", head->dir);
		head = head->next;
	}
}

/**
 * free_path_list - frees the linked list
 */
void free_path_list(path_node_t *head)
{
	path_node_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->dir);
		free(temp);
	}
}

/* main function to test */
int main(void)
{
	path_node_t *head = build_path_list();

	if (!head)
	{
		printf("Failed to build PATH list\n");
		return (1);
	}

	printf("PATH directories:\n");
	print_path_list(head);

	free_path_list(head);
	return (0);
}
