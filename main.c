#include "monty.h"

/**
 *
 *
 *
 */

char *filename;

int main(int argc, char *argv[])
{
	void (*test)(stack_t **, unsigned int);
	char *line_str;
	unsigned int i = 1;

	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	
	while (1)
	{
		line_str = get_file_line(filename, i);
		if (line_str == NULL)
			break;
		test = op_function(strtok(line_str, " "));
		if (test == NULL)
		{
			printf("Can't find function\n");
			break;
		}
		test(&stack, i);
		i++;
	}

	free(stack);
	return (0);
}
