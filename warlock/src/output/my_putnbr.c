/*
** EPITECH PROJECT, 2018
** putnbr
** File description:
** print an int to the standar output
*/

#include "warlock.h"

// sub-function of my_put_number

int get_expection(int nb)
{
    switch (nb) {
    case (0):
        my_putchar('0');
        return (-1);
    case (-2147483648):
        my_putstr("-2147483648");
        return (-1);
    case (2147483647):
        my_putstr("2147483648");
        return (-1);
    default :
        return (0);
    }
}

/*
\fn int my_put_nbr(int nb)
\brief print number on standard output
\param nb : the number to print.
\return 0.
*/

int my_put_nbr(int nb)
{
    int tmp = 0;

    if (get_expection(nb) == -1)
        return (0);
    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
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
