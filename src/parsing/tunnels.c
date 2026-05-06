/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** tunnels
*/

#include "my.h"
#include "print.h"
#include <stdlib.h>

static char *get_first_room(char *line, int *i)
{
    char *name = NULL;
    int j = 0;

    while (line[*i] != '-' && line[*i] != '\0')
        (*i)++;
    name = malloc(sizeof(char) * (*i + 1));
    if (name == NULL)
        return NULL;
    while (j < *i) {
        name[j] = line[j];
        j++;
    }
    name[*i] = '\0';
    return name;
}

static char *get_second_room(char *line, int start)
{
    char *name = NULL;
    int len = 0;
    int i = 0;

    while (line[start + len] != '\n' && line[start + len] != '\0' &&
        line[start + len] != ' ')
        len++;
    name = malloc(sizeof(char) * (len + 1));
    if (name == NULL)
        return NULL;
    while (i < len) {
        name[i] = line[start + i];
        i++;
    }
    name[len] = '\0';
    return name;
}

static void new_matrix(maze_t *maze)
{
    if (maze->matrix == NULL) {
        my_putstr("#tunnels\n");
        maze->matrix = matrix_build(maze->nb_rooms);
    }
}

int add_tunnel(maze_t *maze, char *line)
{
    int i = 0;
    char *room1 = NULL;
    char *room2 = NULL;
    int idx1 = 0;
    int idx2 = 0;

    new_matrix(maze);
    room1 = get_first_room(line, &i);
    room2 = get_second_room(line, i + 1);
    if (room1 == NULL || room2 == NULL)
        return 84;
    idx1 = get_room_index(maze, room1);
    idx2 = get_room_index(maze, room2);
    free(room1);
    free(room2);
    if (idx1 == -1 || idx2 == -1)
        return 84;
    maze->matrix[idx1][idx2] = '1';
    maze->matrix[idx2][idx1] = '1';
    return 0;
}
