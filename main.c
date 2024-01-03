#include "monty.h"

/**
 *
 *
 *
 */

int main(int argc, char *argv[])
{
	int file;
	char *buffer, *token;
	ssize_t BytesRead;
	
	if (argc != 2)
	{
		printf("USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		printf("Error : Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	buffer = malloc(sizeof(char *) * 1000);
	if (buffer == NULL)
		return (0);
	BytesRead = read(file, buffer, 1000);
	if (BytesRead == -1)
	{
		free(buffer);
		close(file);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, " \t\n");
	while (token != NULL)
	{
		token = strtok(NULL, " \t\n");
	}
	free(buffer);
	close(file);
	return (0);
}
