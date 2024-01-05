#include "monty.h"

char *get_file_line(const char *filename,unsigned int line)
{
	char *token = NULL;
	unsigned int counter = 1;

	token = strtok(get_file_buffer(filename), "\n");
	while (counter != line && token != NULL)
	{
		token = strtok(NULL, "\n");
		counter++;
	}

	return (token);
}
