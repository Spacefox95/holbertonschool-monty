#include "monty.h"

/**
 * swap - swap the top two elements
 * @stack: the stack with elements
 * @line_number: line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u : can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = tmp;
}
