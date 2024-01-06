#include "monty.h"

/**
 * add_fct - add at the top of the stack 2 elements
 * @stack: the stack
 * @line_number: the line number
 */

void add_fct(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d : can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	((*stack)->next)->n = ((*stack)->next)->n + (*stack)->n;
	pop_fct(stack, line_number);
}
