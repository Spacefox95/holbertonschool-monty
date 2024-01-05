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
	char *line_str = NULL, *command = NULL;
	unsigned int i = 1, file_lines_count = 0;

	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE : monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	file_lines_count = get_lines_number((const char *) filename);
	
	while (i <= file_lines_count)
	{
		line_str = get_file_line(filename, i);
		if (line_str == NULL)
		{
			i++;
			continue;
		}

		command = strtok(split_until_char((const char *) line_str), " \t\n");
		test = op_function(command);
		if (test == NULL)
		{
			fprintf(stderr, "L<%d>: unknown instruction %s\n", i, line_str);
			exit(EXIT_FAILURE);
		}
		test(&stack, i);
		i++;
	}

	return (0);
}
