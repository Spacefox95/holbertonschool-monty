#include "monty.h"

/**
 * push_fct - add node the the stack
 * @stack: the stack
 * @line_number: line counter
 */

void push_fct(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
