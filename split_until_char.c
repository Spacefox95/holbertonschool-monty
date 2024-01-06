#include "monty.h"

/**
 * split_until_char - check for a char in the line
 * @line_str: the line to check
 * Return: the char found
 */

char *split_until_char(const char *line_str)
{
	char *str;

	str = (char *) line_str;
	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}

	while (*str != '\0' && *str == ' ')
	{
		str++;
	}
	if (*str == '\0')
	{
		return (NULL);
	}
	return (str);
}
