#include "monty.h"

/**
 *m_pstr - ...
 *@head: ...
 *@c: ...
 *Return: ...
 */
void m_pstr(stack_t **head, unsigned int c)
{
	stack_t *tmp;
	(void)c;

	tmp = *head;
	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
        	{
                	break;
        	}
		printf("%c", (char)tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
