#include "monty.h"

/**
 * op_function - select the fct associated to the command
 * @command: the first token input
 * Return: the operation function
 */


void (*(op_function (char *command, stack_t __attribute__((unused)) **stack, unsigned int __attribute__((unused)) line_number)))(stack_t **, unsigned int)
{
	instruction_t com[] = {
		{"push", push_fct},
		{"pall", pall_fct},
		/*{"pint", pint_fct},
		{"pop", pop_fct},
		{"swap", swap_fct},
		{"add", add_fct},
<<<<<<< HEAD
		{"nop", nop_fct},
=======
		{"nop", nop_fct},*/
>>>>>>> nathan
		{NULL, NULL}
	};

	int i = 0;

	while (com[i].f != NULL)
	{
		if (strcmp(command, com[i].opcode) == 0)
			return (com[i].f);
		i++;
	}
	return (NULL);
}
