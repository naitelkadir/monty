#include "monty.h"

/**
 *m_rotr - ...
 *@head: ...
 *@c: ...
 *Return: ...
 */
void m_rotr(stack_t **head, unsigned int c)
{
	stack_t *tmp;
	(void)c;
	
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*head)->prev = tmp;
	(*head) = tmp;
}
