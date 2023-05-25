#include "monty.h"

/**
 *m_sub - ...
 *@head: ...
 *@c: ...
 *Return: ...
 */
void m_sub(stack_t **head, unsigned int c)
{
	stack_t *tmp;
	int m = 0, l;
	
	tmp = *head;
	while(tmp)
	{
		tmp = tmp->next;
		m++;
	}
	if (m < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	l = tmp->next->n - tmp->n;
	tmp->next->n = l;
	*head = tmp->next;
	free(tmp);
}
