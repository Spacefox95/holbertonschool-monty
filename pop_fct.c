#include "monty.h"

/**
 * pop_fct - remove the top element of the stack
 * @stack: the stack
 * @line_number: number of line
 */

void pop_fct(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	tmp = NULL;
}
