/*
** EPITECH PROJECT, 2019
** base.c
** File description:
** base conversion fonction
*/

#include "warlock.h"

char *nb_to_binary(int nb)
{
    int i = 0;
    char *str = clean_alloc(count_digit(nb) * 10);

    while (nb > 0) {
        str[i] = (nb % 2) + 48;
        nb /= 2;
        i += 1;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}

int binary_to_nb(char *str)
{
    int nb = 0;
    int base = 1;
    int len = 0;

    if (DEBUG_MODE == 1)
        debug_log("binary_to_nb()", str);
    while (str[len] != '\0')
        len += 1;
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == '1')
            nb += base;
        base = base * 2;
    }
    return (nb);
}

int octal_to_decimal(int decimal)
{
    int octal = 0;
    int i = 1;

    while (decimal != 0) {
        octal += (decimal % 8) * i;
        decimal /= 8;
        i *= 10;
    }
    return (octal);
}