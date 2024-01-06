#include "monty.h"

/**
 * pint_fct - print the value at the top of the stack
 * @stack: the stack
 * @line_number: line number
 */

void pint_fct(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	printf("%d\n", (*stack)->n);
}
