#include "monty.h"

char *get_file_line(const char *filename,unsigned int line)
{
	char *token = NULL, *buffer;
	unsigned int counter = 1;

	buffer = get_file_buffer(filename);
	token = strtok(buffer, "\n");

	while (counter != line && token != NULL)
	{
		token = strtok(NULL, "\n");
		counter++;
	}

	return (token);
}