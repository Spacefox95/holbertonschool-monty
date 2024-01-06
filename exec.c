#include "monty.h"

/**
 * exec - execute the function and count
 * @command: the function called
 */

void exec(char *command)
{
	unsigned int count = 1;
	stack_t *stack = NULL;
	int check = 0;

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
}
