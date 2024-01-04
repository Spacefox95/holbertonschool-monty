#include "monty.h"

/**
 *
 *
 *
 */

int main(int argc, char *argv[])
{
	void (*test)(stack_t **, unsigned int);
	char *buffer, *line_str;
	void (*function)(stack_t **, unsigned int);
	void (*pall_funct)(stack_t **, unsigned int);
	unsigned int i = 1;

	stack_t *stack;

	if (argc != 2)
	{
		printf("USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}
	filename = argv[1];
	buffer = get_file_buffer(filename);
	line_str = get_file_line(filename, 1);
	
	while (1)
	{
		line_str = get_file_line(filename, i);
		if (line_str == NULL)
			break;
		test = op_function(strtok(line_str, " \t\n"), &stack, i);
		if (test == NULL) 
			break;
		test(&stack, i);
		i++;
	}

	return (0);
}
