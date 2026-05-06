/*
** EPITECH PROJECT, 2026
** G-CPE-200-LIL-2-1-amazed-5
** File description:
** my_strtok
*/

#include "str.h"

int is_delimiter(char c, const char *delim)
{
    int i = 0;

    while (delim[i]) {
        if (c == delim[i])
            return 1;
        i++;
    }
    return 0;
}

char *my_strtok(char *str, const char *delim, char **saveptr)
{
    char *start = NULL;

    if (str != NULL)
        *saveptr = str;
    if (*saveptr == NULL || **saveptr == '\0')
        return NULL;
    while (**saveptr && is_delimiter(**saveptr, delim))
        (*saveptr)++;
    if (**saveptr == '\0')
        return NULL;
    start = *saveptr;
    while (**saveptr && !is_delimiter(**saveptr, delim))
        (*saveptr)++;
    if (**saveptr != '\0') {
        **saveptr = '\0';
        (*saveptr)++;
    } else
        *saveptr = NULL;
    return start;
}
