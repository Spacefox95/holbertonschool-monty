#include "monty.h"

void _free(stack_t **stack)
{
    stack_t *tmp = NULL;

    if (stack == NULL || *stack == NULL)
    {
        return;
    }

    while (*stack != NULL)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
        tmp = NULL;
    }
}