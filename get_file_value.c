#include "monty.h"

/**
 * get_file_value - associate the buffer with the instruction struct
 * @buffer: the command and then the value
 * @com: the struct with function in fct of command
 * Return: 0 if success
 */

void *get_file_value(char *buffer, instruction_t *com)
{
	int i, value, check = 0;
	char *token;
	unsigned int line_str = 1;
	stack_t *stack = NULL;

	token = strtok(buffer, " \t\n");
	while (token != NULL)
	{
		for (i = 0 ; com[i].opcode != NULL ; i++)
		{
			if (strcmp(token, com[i].opcode) == 0)
			{
				if (strcmp(token, "push") == 0)
				{
					token = strtok(NULL, " \t\n");
					if (token != NULL && (*token >= '0' && *token <= '9'))
					{
						value = atoi(token);
						com[i].f(&stack, value);
					}
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", line_str);
						free_stack(stack);
						free(buffer);
						exit(EXIT_FAILURE);
					}
				}
				else
					com[i].f(&stack, line_str);
				check = 1;
				break;
			}
		}
		if (!check)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_str, token);
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\n");
		line_str++;
	}
	return (0);
}
