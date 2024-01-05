#include "monty.h"

char *get_file_buffer(const char *filename)
{
	int file;
	char *buffer;
	ssize_t BytesRead;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (NULL);
	}

	buffer = malloc(1024);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close(file);
		return (NULL);
	}

	BytesRead = read(file, buffer, 1024 - 1);
	if (BytesRead == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", filename);
		free(buffer);
		close(file);
		return (NULL);
	}
	close(file);
	buffer[BytesRead] = '\0';

	return (buffer);
}
