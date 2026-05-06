/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** get_paths
*/

#include "my.h"
#include "print.h"
#include "str.h"

char *get_name_by_index(maze_t *maze, int index)
{
    room_t *temp = maze->rooms;

    for (int i = 0; i < index && temp != NULL; i++)
        temp = temp->next;
    return (temp ? temp->name : NULL);
}

int *fill_path(dijk_t *dijk, int end_idx, int size)
{
    int *path = malloc(sizeof(int) * size);
    int current = end_idx;

    if (!path)
        return NULL;
    for (int i = size - 1; i >= 0; i--) {
        path[i] = current;
        current = dijk->parent[current];
    }
    return path;
}

int *get_path_array(dijk_t *dijk, int end_idx, int *size)
{
    int current = end_idx;

    *size = 0;
    while (current != -1) {
        (*size)++;
        current = dijk->parent[current];
    }
    return fill_path(dijk, end_idx, *size);
}
