#include "monty.h"

/**
 *
 *
 */

void push_fct(stack_t **stack, unsigned int value)
{
	stack_t *new_node;
	new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
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
