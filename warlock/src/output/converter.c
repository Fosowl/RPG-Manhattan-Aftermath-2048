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

/*
\fn char *format_from_human_base(char *calculated, char *base)
\brief convert a number from any base to any base.
\param calculated : the number to convert in string format.
\param base : the base you convert to.
\return a string that result of the convertion.
*/

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

/*
\fn void put_binary(int nb)
\brief print number in binary.
\param nb : the number to print in binary.
\return nothing.
*/

void put_binary(int nb)
{
    char *result = NULL;

    result = format_from_human_base(my_itoa(nb), "01");
    my_putstr(result);
}

/*
\fn void put_hexa(int nb)
\brief print number in hexadecimal
\param nb : the number to print in hexadecimal.
\return nothing.
*/

void put_hexa(void *number)
{
    int nb = (long long int)number;
    char *result = NULL;

    result = format_from_human_base(my_itoa(nb), "0123456789abcdef");
    my_putstr(result);
}

/*
\fn int put_capital_hexa(void *number)
\brief print number in hexadecimal
\param number : the number to print in hexadecimal in maj.
\return 0.
*/

int put_capital_hexa(void *number)
{
    char *result = NULL;
    int nb = (long long int)number;

    result = format_from_human_base(my_itoa(nb), "0123456789ABCDEF");
    my_putstr(result);
    return (0);
}