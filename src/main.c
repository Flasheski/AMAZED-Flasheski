/*
** EPITECH PROJECT, 2026
** G-CPE-200-LIL-2-1-amazed-5
** File description:
** main
*/

#include "print.h"
#include "str.h"
#include "my.h"

int main(int argc, char **argv)
{
    maze_t maze;

    init_maze(&maze);
    if (parse_labyrinth(&maze) == 84) {
        free_maze(&maze);
        return 84;
    }
    if (!maze.start || !maze.end || !maze.matrix) {
        my_putchar('\n');
        return 84;
    }
    if (solve_maze(&maze) == 84) {
        free_maze(&maze);
        return 84;
    }
    (void)argc;
    (void)argv;
    free_maze(&maze);
    return 0;
}
