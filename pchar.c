#include "monty.h"

/**
 *m_pchar - ...
 *@head: ...
 *@c: ...
 *Return: ...
 */
void m_pchar(stack_t **head, unsigned int c)
{
	stack_t *tmp;
	
	tmp = *head;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (tmp->n > 128 || tmp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)(tmp->n));
}
