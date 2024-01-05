#include "monty.h"

void pop_fct(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
    stack_t *tmp;

    if (stack == NULL || *stack == NULL)
    {
        return;
    }

    tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);
    tmp = NULL;
}