#include "monty.h"

/**
 *
 *
 *
 */

void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp;
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
