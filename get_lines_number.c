#include "monty.h"

unsigned int get_lines_number(const char *filename)
{
    unsigned int counter = 0;
    char *buffer = NULL;

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