#include "monty.h"

/**
 *m_pall - ...
 *@head: ...
 *@c: ...
 *Return: ...
 */
void m_pall(stack_t **head, unsigned int c)
{
	stack_t *tmp;
	(void)c;
	
	tmp = *head;
	if (tmp == NULL)
	{
		return;
	}
	while(tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
