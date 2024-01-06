#include "monty.h"

/**
 * main - main function for a monty interpreter
 * @argc: argument passed in stream counter
 * @argv: program and name of the file
 * Return: 0 if success
 */

int main(int argc, char *argv[])
{
	char *command = NULL, *buffer = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}

	buffer = get_file_buffer(argv[1]);
	command = strtok(buffer, " \t\n");
	exec(command, &stack);
	free(command);
	_free(&stack);

	return (0);
}
