#include "monty.h"

/**
 * main - main function for a monty interpreter
 * @argc: argument passed in stream counter
 * @argv: program and name of the file
 * Return: 0 if success
 */

int main(int argc, char *argv[])
{
	char *buffer, *token;

	stack_t *stack = NULL;

	instruction_t com[] = {
		{"push", push_fct},
		{"pall", pall_fct},

		/**
		 * {"pint", pint_fct},
		 * {"pop", pop_fct},
		 * {"swap", swap_fct},
		 * {"add", add_fct},
		 * {"nop", nop_fct},
		 */

		{NULL, NULL}
	};

	if (argc != 2)
	{
		printf("USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}
	buffer = get_file_buffer(argv[1]);
	token = get_file_value(buffer, com);

	free_stack(stack);
	free(token);
	free(buffer);
	return (0);
}
