#include "monty.h"

char *split_until_int(const char *line_str)
{
    char *str;

    str = (char *) line_str;
    if (str == NULL || *str == '\0')
    {
        return (NULL);
    }

    while (*str != '\0' && !(*str <= '9' && *str >= '0'))
    {
        str++;
    }
    if (*str == '\0')
    {
        return (NULL);
    }
    return (str);
}