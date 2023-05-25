#include "monty.h"

/**
 *m_pop - ...
 *@head: ...
 *@c: ...
 *Return: ...
 */
void m_pop(stack_t **head, unsigned int c)
{
	stack_t *tmp;
	
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = tmp->next;
	free(tmp);
}
