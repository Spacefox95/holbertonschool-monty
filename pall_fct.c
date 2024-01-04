#include "monty.h"

void pall_fct(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = stack;
    if (stack == NULL || *stack == NULL)
    {
        return (NULL);
    }
    
    while (temp->next != NULL)
    {
        printf("%d", temp->n);
        temp = temp->next;
    }

}