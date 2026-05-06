/*
** EPITECH PROJECT, 2026
** libs
** File description:
** my_strlen
*/

#include "print.h"

int my_strlen(char const *str)
{
    int number = 0;

    if (str == NULL)
        return 0;
    while (str[number] != '\0') {
        number++;
    }
    return number;
}
