#include "monty.h"

/**
 * op_function - select the fct associated to the command
 * @command: the first token input
 * Return: the operation function
 */


void (*op_function(char *command))(stack_t **stack, unsigned int line_number)
{
	instruction_t com[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i = 0;

	while (com[i].f != NULL && command != NULL)
	{
		if (strcmp(command, com[i].opcode) == 0)
			return (com[i].f);
		i++;
	}
	return (NULL);
}
