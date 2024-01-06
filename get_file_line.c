#include "monty.h"

/**
 * get_file_line - tokenize the file to get the right instruction
 * @filename: the file read
 * @line: number of lines in the file
 * Return: the token
 */

char *get_file_line(const char *filename, unsigned int line)
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
