#include "monty.h"

void pint_fct(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
    if (stack == NULL || *stack == NULL)
    {
        return;
    }
    printf("%d\n", (*stack)->n);
}