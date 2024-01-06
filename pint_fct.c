#include "monty.h"

/**
 * pint_fct - print the value at the top of the stack
 * @stack: the stack
 * @line_number: line number
 */

void pint_fct(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
