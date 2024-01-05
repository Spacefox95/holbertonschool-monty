#include "monty.h"

/**
 *
 *
 *
 */

int main(int argc, char *argv[])
{
	char *buffer, *token;
	int i, check, value;
	unsigned int line_str = 1;

	stack_t *stack = NULL;

	instruction_t com[] = {
		{"push", push_fct},
		{"pall", pall_fct},
		/*{"pint", pint_fct},
		  {"pop", pop_fct},
		  {"swap", swap_fct},
		  {"add", add_fct},
		  {"nop", nop_fct},*/
		{NULL, NULL}
	};

	if (argc != 2)
	{
		printf("USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}
	buffer = get_file_buffer(argv[1]);
	token = strtok(buffer, " \t\n");

	while (token != NULL)
	{
		for (i = 0 ; com[i].opcode != NULL ; i++)
		{
			if (strcmp(token, com[i].opcode) == 0)
			{
				if (strcmp (token, "push") == 0)
				{
					token = strtok(NULL, " \t\n");
					if (token != NULL)
					{
						value = atoi(token);
						com[i].f(&stack, value);
					}
					else
					{
						fprintf(stderr, "Missing value for push");
						free_stack(stack);
						free(buffer);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					com[i].f(&stack, line_str);
				}
				check = 1;
				break;
			}
		}

		if (!check)
		{
			fprintf(stderr, "L<line_number>: unknown instruction <opcode>\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\n");
		line_str++;
	}
	free_stack(stack);
	free(buffer);
	return (0);
}
