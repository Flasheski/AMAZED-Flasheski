##
## EPITECH PROJECT, 2026
## makefile
## File description:
## makefile for strings
##

SRC =	my_atoi.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_strtok.c \
		my_strupcase.c

OBJ = $(SRC:.c=.o)
NAME	=	libstr.a
CFLAGS	= 	-Wall -Wextra

GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@echo "$(GREEN)		 -------------- | Creating $(NAME) | -------------- "
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ../
	cp str.h ../../include
	@echo "$(GREEN)	  	 -------------- |  $(NAME) built ! | -------------- $(RESET)"
	@echo "\n"

%.o: 	%.c
	@echo "$(CYAN) Compiling $<...$(RESET)"
	epiclang -c $< -o $@ $(CFLAGS)

clean:
	@echo "\n"
	@echo "$(YELLOW)	 	 -------------- | Cleaning objects | -------------- "
	rm -f $(OBJ)
	rm -f *.gc*
	@echo "$(RESET)"

fclean: clean
	@echo "$(YELLOW)	 	 -------------- | Removing library | -------------- $(RESET)"
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
