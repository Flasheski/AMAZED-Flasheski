/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** implement_dijk
*/

#include "str.h"
#include "print.h"
#include "my.h"

dijk_t *init_dijk(int nb_rooms)
{
    dijk_t *dijk = malloc(sizeof(dijk_t));

    if (!dijk)
        return NULL;
    dijk->distance = malloc(sizeof(int) * nb_rooms);
    dijk->parent = malloc(sizeof(int) * nb_rooms);
    dijk->visited = malloc(sizeof(int) * nb_rooms);
    dijk->queue = malloc(sizeof(int) * nb_rooms);
    dijk->head = 0;
    dijk->rear = 0;
    for (int i = 0; i < nb_rooms; i++) {
        dijk->distance[i] = -1;
        dijk->parent[i] = -1;
        dijk->visited[i] = 0;
    }
    return dijk;
}

void free_dijk(dijk_t *dijk)
{
    free(dijk->distance);
    free(dijk->parent);
    free(dijk->visited);
    free(dijk->queue);
    free(dijk);
}
