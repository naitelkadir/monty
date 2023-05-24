#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};
/**
 *main - ...
 *@argc: ...
 *@argv: ...
 *Return: ...
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read = 1;
	stack_t *head = NULL;
	unsigned int c = 0;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "ERROR: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		content = NULL;
		read = custom_getline(&content, &size, file);
		bus.content = content;
		c++;
		if (read > 0)
		{
			m_execute(content, &head, c, file);
		}
	}
	free(content);
	free_stack(head);
	fclose(file);
	return (0);
}
