#include "monty.h"

/**
 * push - add node the the stack
 * @stack: the stack
 * @line_number: line counter
 * @buffer: the character to add
 */

void push(stack_t **stack, unsigned int line_number, char *buffer)
{
	stack_t *new_node;
	int value, i;

	new_node = (stack_t *) malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0 ; buffer[i] != '\0' ; i++)
	{
		if (!isdigit((unsigned char)buffer[i]) && !(i == 0 && buffer[i] == '-'))
		{
			printf("L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	value = atoi(buffer);
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
