/*
** EPITECH PROJECT, 2020
** call_function.c
** File description:
** function needed by call in my_printf.c
*/

#include "warlock.h"

// all the function below are the same as
// the one whitout "call_" expect they are adapted to be
// compatible with the array of function pointer use
// by the my_printf function found in my_printf.c

int call_my_putchar(void *potato)
{
    char c = (long long int) potato;
    write(1, &c, 1);
    return (0);
}

int call_my_put_nbr(void *number)
{
    int tmp = 0;
    long long int nb = (long long int) number;

    if (get_expection(nb) == -1)
        return (0);
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb >= 10) {
        tmp = (nb % 10);
        nb = (nb - tmp) / 10;
        my_put_nbr(nb);
        my_putchar(tmp + 48);
    }
    else
        my_putchar((nb % 10) + 48);
    return (0);
}

int call_put_binary(void *number)
{
    char *result = NULL;
    long long int nb = (long long int) number;

    result = format_from_human_base(my_itoa(nb), "01");
    my_putstr(result);
    return (0);
}

int call_my_putstr(void *string)
{
    char *str = (char *) string;

    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}