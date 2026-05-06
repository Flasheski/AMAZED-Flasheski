/*
** EPITECH PROJECT, 2026
** AMAZED
** File description:
** header
*/

#include "print.h"
#include "str.h"
#include <stddef.h>

#ifndef MY_H_
    #define MY_H_

typedef struct room_s {
    char *name;
    struct room_s *next;
} room_t;

typedef struct robot_s {
    int id;
    int status;
    char *pos;
    struct robot_s *next;
} robot_t;

typedef struct maze_s {
    int nb_robots;
    char *start;
    char *end;
    room_t *rooms;
    int nb_rooms;
    char **path;
    char **matrix;
    struct robot_t **robots;
} maze_t;

typedef struct dijk_s {
    int *distance;
    int *parent;
    int *visited;
    int *queue;
    int head;
    int rear;
} dijk_t;

typedef struct rbt_moves_s {
    int id;
    int *path;
    int path_position;
} rbt_moves_t;

// maze
void init_maze(maze_t *maze);
int parse_labyrinth(maze_t *maze);
int solve_maze(maze_t *maze);
void free_maze(maze_t *maze);
// rooms and tunnels
int add_room(maze_t *maze, char *name);
int get_room_index(maze_t *maze, char *name);
int add_tunnel(maze_t *maze, char *line);
// commands
void handle_commands(char *line, int *state);
// matrix
char *matrix_new_line(int size);
char **matrix_build(int size);
// dijkstra functions
dijk_t *init_dijk(int nb_rooms);
void free_dijk(dijk_t *dijk);
void check_neighbors(maze_t *maze, dijk_t *dijk, int current);
// paths
int *get_path_array(dijk_t *dijk, int end_idx, int *size);
char *get_name_by_index(maze_t *maze, int index);
// display
void display_moves(maze_t *maze, int *path, int size_path);
void handle_final_display(maze_t *maze, dijk_t *dijk, int end_idx);

#endif
