/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** solve_maze
*/

#include "my.h"
#include "print.h"
#include "str.h"

void setup_start(dijk_t *dijk, int start_idx)
{
    dijk->visited[start_idx] = 1;
    dijk->distance[start_idx] = 0;
    dijk->queue[dijk->rear] = start_idx;
    dijk->rear++;
}

int run_dijkstra_loop(maze_t *maze, dijk_t *dijk, int end_idx)
{
    int current = 0;

    while (dijk->head < dijk->rear) {
        current = dijk->queue[dijk->head];
        dijk->head++;
        if (current == end_idx) {
            handle_final_display(maze, dijk, end_idx);
            return 0;
        }
        check_neighbors(maze, dijk, current);
    }
    return 84;
}

int solve_maze(maze_t *maze)
{
    dijk_t *dijk = NULL;
    int start_idx = get_room_index(maze, maze->start);
    int end_idx = get_room_index(maze, maze->end);
    int status = 0;

    if (start_idx == -1 || end_idx == -1 || maze->nb_rooms <= 0)
        return 84;
    dijk = init_dijk(maze->nb_rooms);
    if (!dijk)
        return 84;
    setup_start(dijk, start_idx);
    status = run_dijkstra_loop(maze, dijk, end_idx);
    free_dijk(dijk);
    return status;
}
