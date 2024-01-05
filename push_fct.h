#include "monty.h"

void push_fct(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    char *line;
    
    new_node = (stack_t *) malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = line_number;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
        *stack = new_node;
    }
    else
    {
        *stack = new_node;
    }

    line = get_file_line(filename, line_number);
    (*stack)->n = atoi(line);
}