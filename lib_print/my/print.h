/*
** EPITECH PROJECT, 2025
** my_h
** File description:
** my_h
*/

#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#ifndef PRINT_H_
    #define PRINT_H_

int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
void my_puterror(char *str);
char *my_revstr(char *str);
int my_strlen(char const *str);

#endif /* !PRINT_H_ */
