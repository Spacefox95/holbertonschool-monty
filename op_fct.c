#include "monty.h"

void push_fct(int *buffer, unsigned int line_number)
{
    stack_t **stack *newNode;
    newNode = (struct stack_t*)malloc(sizeof(stack_t **stack));
    newNode->n = buffer;
    if (prev == NULL)
    newNode->next = NULL;
    else
    newNode->next = prev;
    prev = newNode;

}