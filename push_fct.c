#include "monty.h"

void push_fct(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *line, *line_split;
	
	if (stack == NULL)
		return;
	
	line = get_file_line(filename, line_number);
	line_split = split_until_int(line);
	if (line_split == NULL || atoi(line_split) == 0)
	{
		
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(line);
		exit(EXIT_FAILURE);
	}

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->n = atoi(line_split);
	
	if (*stack != NULL)
		new_node->next = *stack;
	
	*stack = new_node;
}

char *split_until_int(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);

	while (*str != '\0' && !('0' <= *str && *str <= '9'))
	{
		*str++;
	}

	if (*str != '\0')
		return (str);

	return (NULL);
}
