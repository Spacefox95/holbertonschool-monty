#include "monty.h"

/**
 * push_fct - add node the the stack
 * @stack: the stack
 * @line_number: line counter
 * @buffer: the character to add
 */

void push_fct(stack_t **stack, unsigned int line_number, const char *buffer)
{
	stack_t *new_node;
	int value;

	new_node = (stack_t *) malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	value = atoi(buffer);
	if (value == 0)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
