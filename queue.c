#include "monty.h"

/**
 *f_queue - ...
 *@head: ...
 *@counter: ...
 *Return: ...
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}
/**
 *addqueue - ...
 *@n: ...
 *@head: ...
 *Return: ...
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new, *tmp;
	
	tmp = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed");
	}
	new->n = n;
	new->next = NULL;
	if (tmp)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
	}
	if (!tmp)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		tmp->next = new;
		new->prev = tmp;
	}
}
