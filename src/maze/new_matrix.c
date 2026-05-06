/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** new matrix
*/

#include "my.h"
#include <stdlib.h>

char *matrix_new_line(int size)
{
    char *line = NULL;
    int i = 0;

    line = malloc(sizeof(char) * (size + 1));
    if (line == NULL)
        return NULL;
    while (i < size) {
        line[i] = '0';
        i++;
    }
    line[i] = '\0';
    return line;
}

char **matrix_build(int size)
{
    char **mat = NULL;
    int i = 0;

    mat = malloc(sizeof(char *) * (size + 1));
    if (mat == NULL)
        return NULL;
    while (i < size) {
        mat[i] = matrix_new_line(size);
        if (mat[i] == NULL)
            return NULL;
        i++;
    }
    mat[i] = NULL;
    return mat;
}
