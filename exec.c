#include "monty.h"

/**
 * exec - execute the function and count
 * @command: the function called
 * @stack: the stack used
 */

void exec(char *command, stack_t **stack)
{
	unsigned int count = 1;
	int check = 0;

	while (command != NULL)
	{
		if (check == 1)
		{
			push(stack, count, command);
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
				op_function(command)(stack, count);
			}
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", count, command);
				exit(EXIT_FAILURE);
			}
		}
		count++;
		command = strtok(NULL, " \t\n");
	}
}
