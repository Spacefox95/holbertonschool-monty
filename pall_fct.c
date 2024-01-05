#include "monty.h"

/**
 * pall_fct - fct that display the stack
 * @stack: the stack
 * @line_number: line counter
 */

void pall_fct(stack_t **stack, unsigned int __attribute__((unused))line_number)
{
	stack_t *temp = *stack;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
