##
## EPITECH PROJECT, 2026
## G-CPE-200-LIL-2-1-AMAZED-5
## File description:
## Makefile
##

CC      =   epiclang

SRC =   src/algo/check_neighbors.c \
		src/algo/implement_dijk.c \
		src/maze/init_maze.c \
		src/maze/new_matrix.c \
		src/maze/solve_maze.c \
		src/parsing/moves.c \
		src/parsing/parsing.c \
		src/parsing/rooms.c \
		src/parsing/tunnels.c \
		src/paths/commands.c \
		src/paths/get_paths.c \
		src/main.c

OBJ =   $(SRC:.c=.o)

NAME    =   amazed

CPPFLAGS =  -I./include
CFLAGS  =   -Wall -Wextra
LIB_FLAGS = -L./lib_print -lprint -L./lib_str -lstr

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib_print/my
	$(MAKE) -C ./lib_str/my
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(LIB_FLAGS)

clean:
	$(MAKE) -C ./lib_print/my clean
	$(MAKE) -C ./lib_str/my clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C ./lib_print/my fclean
	$(MAKE) -C ./lib_str/my fclean
	rm -f $(NAME)
	@echo "\n"

re: fclean all

.PHONY: all test clean fclean re
