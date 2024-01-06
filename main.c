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
	unsigned int count = 1;
	stack_t *stack = NULL;
	int check = 0;

	if (argc != 2)
	{
		printf("USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}

	buffer = get_file_buffer(argv[1]);
	command = strtok(buffer, " \t\n");
	while (command != NULL)
	{
		if (check == 1)
		{
			push_fct(&stack, count, command);
			check = 0;
			command = strtok(NULL, " \t\n");
			count++;
			continue;
		}
		else if (strcmp(command, "push") == 0)
		{
			check = 1;
			command = strtok(NULL, " \t\n");
			continue;
		}
		else
		{
			if (op_function(command) != 0)
			{
				op_function(command)(&stack, count);
			}
			else
			{
				fprintf(stderr, "L<%u>: unknown instruction %s\n", count, command);
				exit(EXIT_FAILURE);
			}
		}
		count++;
		command = strtok(NULL, " \t\n");
	}
	return (0);
}
