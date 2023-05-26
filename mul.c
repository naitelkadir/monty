#include "monty.h"

/**
 *m_mul - ...
 *@head: ...
 *@c: ...
 *Return: ...
 */
void m_mul(stack_t **head, unsigned int c)
{
	stack_t *tmp;
	int m = 0, k;
	
	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		m++;
	}
	if (m < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	k = tmp->n * tmp->next->n;
	tmp->next->n = k;
	*head = tmp->next;
	free(tmp);
}	
