#include "monty.h"

/**
 *m_mod - ...
 *@head: ...
 *@c: ...
 *Return: ...
 */
void m_mod(stack_t **head, unsigned int c)
{
	stack_t *tmp;
	int m = 0, l;
	
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
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	l = tmp->next->n % tmp->n;
	tmp->next->n = l;
	*head = tmp->next;
	free(tmp);
}
