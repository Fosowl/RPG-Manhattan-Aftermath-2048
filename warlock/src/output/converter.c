/*
** EPITECH PROJECT, 2019
** converter.c
** File description:
** hexa
*/

#include "warlock.h"

static char revaluate(int num, char *base)
{
    return (base[num]);
}

char *format_from_human_base(char *calculated, char *base)
{
    int baseLen = my_strlen(base);
    long long int nb = my_atoi(calculated);
    int index = 0;
    char *result = NULL;

    result = malloc(sizeof(char) * 1000);
    if (result == NULL)
        return (NULL);
    for (; nb > 0; index++) {
        result[index] = revaluate(nb % baseLen, base);
        nb /= baseLen;
    }
    result[index] = '\0';
    my_revstr(result);
    return (result);
}

void put_binary(int nb)
{
    char *result = NULL;

    result = format_from_human_base(my_itoa(nb), "01");
    my_putstr(result);
}

void put_hexa(void *number)
{
    int nb = (long long int)number;
    char *result = NULL;

    result = format_from_human_base(my_itoa(nb), "0123456789abcdef");
    my_putstr(result);
}

int put_capital_hexa(void *number)
{
    char *result = NULL;
    int nb = (long long int)number;

    result = format_from_human_base(my_itoa(nb), "0123456789ABCDEF");
    my_putstr(result);
    return (0);
}