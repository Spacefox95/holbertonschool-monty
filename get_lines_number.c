#include "monty.h"

/**
 * get_lines_number - counter the lines in the file
 * @filename: the file
 * Return: number of line
 */

unsigned int get_lines_number(const char *filename)
{
	unsigned int counter = 0;
	char *buffer;

	if (filename == NULL)
	{
		return (0);
	}

	buffer = get_file_buffer(filename);
	if (buffer == NULL)
	{
		return (0);
	}

	while (*buffer != '\0')
	{
		if (*buffer == '\n')
		{
			counter++;
		}
		buffer++;
	}

	return (counter);
}
