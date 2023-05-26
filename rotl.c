#include "monty.h"

/**
 *m_rot - ...
 *@head: ...
 *@c: ...
 *Return: ...
 */
void m_rotl(stack_t **head, unsigned int c)
{
	stack_t *tmp, *new;
	(void)c;

	tmp = *head;
	if (*head == NULL || tmp->next == NULL)
	{
		return;
	}
	new = (*head)->next;
	new->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = new;
}
