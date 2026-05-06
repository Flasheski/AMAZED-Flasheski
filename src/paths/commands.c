/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** commands
*/

#include "str.h"
#include "print.h"
#include "my.h"

void handle_commands_2(char *line, maze_t *maze, int *state, size_t len)
{
    if (*state == 1) {
        if (getline(&line, &len, stdin) != -1) {
            maze->start = my_strdup(line);
            my_putstr(line);
            return;
        }
    }
    if (*state == 2) {
        if (getline(&line, &len, stdin) != -1) {
            maze->end = my_strdup(line);
            my_putstr(line);
            return;
        }
    }
}

void handle_commands(char *line, int *state)
{
    if (my_strcmp(line, "##start\n") == 0)
        *state = 1;
    if (my_strcmp(line, "##end\n") == 0)
        *state = 2;
}
