#include "monty.h"

/**
 *m_execute - ...
 *@head: ...
 *@content: ...
 *@c: ...
 *@file: ...
 *Return: ...
 */
int m_execute(char *content, stack_t **head, unsigned int c, FILE *file)
{
	instruction_t command[] = {
					{"push", m_push},
					{"pall", m_pall},
					{"pint", f_pint},
					{"nop", m_nop},
					{"add", m_add},
					{"sub", m_sub},
					{"div", m_div},
					{"swap", m_swap},
					{"pop", m_pop},
					{"mul", m_mul},
					{"mod", m_mod},
					{"pchar", m_pchar},
					{"pstr", m_pstr},
					{"rotl", m_rotl},
					{"rotr", m_rotr},
					{"queue",f_queue},
					{"stack", m_stack},
					{NULL, NULL}
					};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
	{
		return (0);
	}
	bus.arg = strtok(NULL, " \n\t");
	while (command[i].opcode && op)
	{
		if (strcmp(op, command[i].opcode) == 0)
		{
			command[i].f(head, c);
			return (0);
		}
		i++;
	}
	if (op && command[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", c, op);
		fclose(file);
		free(content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}

