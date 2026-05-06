/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** check_neighbors
*/

#include "my.h"
#include "print.h"
#include "str.h"

void check_neighbors(maze_t *maze, dijk_t *dijk, int current)
{
    if (!maze || !maze->matrix)
        return;
    for (int i = 0; i < maze->nb_rooms; i++) {
        if (maze->matrix[current][i] == '1' && dijk->visited[i] == 0) {
            dijk->visited[i] = 1;
            dijk->parent[i] = current;
            dijk->distance[i] = dijk->distance[current] + 1;
            dijk->queue[dijk->rear] = i;
            dijk->rear++;
        }
    }
}
