##
## EPITECH PROJECT, 2026
## makefile
## File description:
## makefile for strings
##

SRC =	my_put_nbr.c \
		my_putchar.c \
		my_puterror.c \
		my_putstr.c \
		my_revstr.c

OBJ = $(SRC:.c=.o)
NAME	=	libprint.a
CFLAGS	= 	-Wall -Wextra

BBLACK = \033[1;30m
PINK = \033[0;35m
BPINK = \033[1;35m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@echo "$(BBLACK)		 -------------- | Creating $(NAME) | -------------- "
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ../
	cp print.h ../../include
	@echo "$(BBLACK)	  	 -------------- |  $(NAME) built ! | -------------- $(RESET)"
	@echo "\n"

%.o: 	%.c
	@echo "$(PINK) Compiling $<...$(RESET)"
	epiclang -c $< -o $@ $(CFLAGS)

clean:
	@echo "\n"
	@echo "$(BPINK)	 	 -------------- |  Cleaning objects ! | -------------- "
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	@echo "$(BPINK)	 	 -------------- | Removing library | -------------- "
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
