#include "monty.h"

/**
 * free_stack - free the stack
 * @stack: the stack associated
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
