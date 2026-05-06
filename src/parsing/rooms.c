/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** rooms
*/

#include "my.h"
#include "str.h"
#include <stdlib.h>

int get_room_index(maze_t *maze, char *name)
{
    int i = 0;
    room_t *temp = NULL;

    temp = maze->rooms;
    while (temp != NULL) {
        if (my_strcmp(temp->name, name) == 0)
            return i;
        temp = temp->next;
        i++;
    }
    return -1;
}

int add_room(maze_t *maze, char *name)
{
    room_t *new_room;
    room_t *temp;

    new_room = malloc(sizeof(room_t));
    temp = maze->rooms;
    if (new_room == NULL)
        return 84;
    new_room->name = name;
    new_room->next = NULL;
    maze->nb_rooms++;
    if (maze->rooms == NULL) {
        maze->rooms = new_room;
        return 0;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_room;
    return 0;
}
