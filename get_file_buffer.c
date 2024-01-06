#include "monty.h"

/**
 * get_file_buffer - open the file and read it
 * @filename: name of the file
 * Return: the read file
 */

char *get_file_buffer(char *filename)
{
	int file;
	char *buffer;
	ssize_t BytesRead;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close(file);
		exit(EXIT_FAILURE);
	}

	BytesRead = read(file, buffer, 1024);
	if (BytesRead == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", filename);
		close(file);
		exit(EXIT_FAILURE);
	}
	close(file);
	buffer[BytesRead] = '\0';

	return (buffer);
}
