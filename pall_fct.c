#include "monty.h"

/**
 * pall - fct that display the stack
 * @stack: the stack
 * @line_number: line counter
 */

void pall(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}
