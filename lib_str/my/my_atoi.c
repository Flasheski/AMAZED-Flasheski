/*
** EPITECH PROJECT, 2025
** SETTING UP
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int result = 0;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}
