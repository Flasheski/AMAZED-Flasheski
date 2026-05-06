/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** init_maze
*/

#include "print.h"
#include "str.h"
#include "my.h"

void init_maze(maze_t *maze)
{
    maze->nb_robots = 0;
    maze->start = NULL;
    maze->end = NULL;
    maze->rooms = NULL;
    maze->nb_rooms = 0;
    maze->path = NULL;
    maze->matrix = NULL;
    maze->robots = NULL;
}

static void free_matrix(char **matrix, int size)
{
    int i = 0;

    if (matrix == NULL) {
        return;
    }
    while (i < size) {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

void free_maze(maze_t *maze)
{
    room_t *temp = maze->rooms;
    room_t *next = NULL;

    while (temp != NULL) {
        next = temp->next;
        if (temp->name != NULL) {
            free(temp->name);
        }
        free(temp);
        temp = next;
    }
    free_matrix(maze->matrix, maze->nb_rooms);
}
