#include "monty.h"

void push_fct(stack_t **stack, unsigned int line_number)
{
    stack_t *newNode;
    newNode = (struct stack_t*)malloc(sizeof(stack_t **stack));
    newNode->n = buffer;
    if (prev == NULL)
    newNode->next = NULL;
    else
    newNode->next = prev;
    prev = newNode;
    
}