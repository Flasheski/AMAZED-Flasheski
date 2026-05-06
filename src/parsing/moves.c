/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** moves
*/

#include "my.h"
#include "print.h"
#include "str.h"

int can_move(rbt_moves_t *m, int i, int path_size)
{
    if (m[i].path_position >= path_size - 1)
        return (0);
    if (i == 0)
        return (1);
    if (m[i].path_position + 1 < m[i - 1].path_position)
        return (1);
    if (m[i].path_position + 1 == path_size - 1)
        return (1);
    return (0);
}

void update_robot(maze_t *maze, rbt_moves_t *m, int i, int *first)
{
    char *name = NULL;

    m[i].path_position++;
    name = get_name_by_index(maze, m[i].path[m[i].path_position]);
    if (!(*first))
        my_putchar(' ');
    my_putchar('P');
    my_put_nbr(m[i].id);
    my_putchar('-');
    my_putstr(name);
    *first = 0;
}

int run_one_lap(maze_t *maze, rbt_moves_t *m, int path_size)
{
    int finished = 0;
    int first = 1;

    for (int i = 0; i < maze->nb_robots; i++) {
        if (can_move(m, i, path_size))
            update_robot(maze, m, i, &first);
        if (m[i].path_position == path_size - 1)
            finished++;
    }
    if (finished < maze->nb_robots)
        my_putchar('\n');
    return finished;
}

void display_moves(maze_t *maze, int *path, int size_path)
{
    rbt_moves_t *moves = malloc(sizeof(rbt_moves_t) * maze->nb_robots);
    int finished = 0;

    if (!moves)
        return;
    for (int i = 0; i < maze->nb_robots; i++) {
        moves[i].id = i + 1;
        moves[i].path = path;
        moves[i].path_position = 0;
    }
    my_putstr("\n#moves\n");
    while (finished < maze->nb_robots) {
        finished = run_one_lap(maze, moves, size_path);
    }
    my_putchar('\n');
    free(moves);
}

void handle_final_display(maze_t *maze, dijk_t *dijk, int end_idx)
{
    int path_size = 0;
    int *path = get_path_array(dijk, end_idx, &path_size);

    if (path != NULL) {
        display_moves(maze, path, path_size);
        free(path);
    }
}
