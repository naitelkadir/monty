#include "monty.h"

/**
 *addnode - ...
 *@head: ...
 *@n: ...
 *Return: ...
 */
void addnode(stack_t **head, int n)
{
	stack_t *new, *tmp;
	
	tmp = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (tmp)
	{
		tmp->prev = new;
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
