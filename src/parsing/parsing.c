/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** parsing
*/

#include "print.h"
#include "str.h"
#include "my.h"
#include <stdlib.h>

static int is_whitespace(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
        return 1;
    return 0;
}

static int is_link(char *line)
{
    int i = 0;

    while (line[i]) {
        if (line[i] == '-')
            return 1;
        i++;
    }
    return 0;
}

static char *get_room_name(char *line)
{
    int i = 0;
    char *name = NULL;
    int j = 0;

    while (line[i] && !is_whitespace(line[i]))
        i++;
    if (i == 0)
        return NULL;
    name = malloc(sizeof(char) * (i + 1));
    if (name == NULL)
        return NULL;
    while (j < i) {
        name[j] = line[j];
        j++;
    }
    name[i] = '\0';
    return name;
}

static void assign_room(maze_t *maze, char *room_name, int *state)
{
    if (*state == 1) {
        maze->start = room_name;
        *state = 0;
    } else if (*state == 2) {
        maze->end = room_name;
        *state = 0;
    }
}

static int process_room(char *line, maze_t *maze, int *state)
{
    char *room_name = NULL;

    if (maze->matrix != NULL)
        return 84;
    my_putstr(line);
    room_name = get_room_name(line);
    if (room_name == NULL)
        return 84;
    assign_room(maze, room_name, state);
    if (add_room(maze, room_name) == 84)
        return 84;
    return 0;
}

static int process_line(char *line, maze_t *maze, int *state)
{
    if (line[0] == '\n')
        return 84;
    if (line[0] == '#') {
        my_putstr(line);
        handle_commands(line, state);
        return 0;
    }
    if (is_link(line)) {
        if (add_tunnel(maze, line) == 84)
            return 84;
        my_putstr(line);
        return 0;
    }
    return process_room(line, maze, state);
}

int parse_labyrinth(maze_t *maze)
{
    char *line = NULL;
    size_t len = 0;
    int state = 0;

    if (getline(&line, &len, stdin) == -1)
        return 84;
    maze->nb_robots = my_atoi(line);
    if (maze->nb_robots <= 0)
        return 84;
    my_putstr("#number_of_robots\n");
    my_put_nbr(maze->nb_robots);
    my_putchar('\n');
    my_putstr("#rooms\n");
    while (getline(&line, &len, stdin) != -1) {
        if (process_line(line, maze, &state) == 84)
            break;
    }
    free(line);
    return 0;
}
