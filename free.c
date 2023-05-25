#include "monty.h"

/**
 *free_stack - ...
 *@head: ...
 *Return: ...
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;
	
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		free(head);
		head = tmp;
	}
}
