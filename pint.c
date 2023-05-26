#include "monty.h"

/**
 *f_pint - ...
 *@head: ...
 *@c: ...
 *Return: ...
 */
void f_pint(stack_t **head, unsigned int c)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", c);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
