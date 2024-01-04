#include "monty.h"

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
