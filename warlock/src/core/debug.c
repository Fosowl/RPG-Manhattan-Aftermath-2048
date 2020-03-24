/*
** EPITECH PROJECT, 2020
** warlock
** File description:
** debug
*/

#include "warlock/core.h"
#include "warlock/output.h"

void debug_log(char *text, void *adress)
{
    my_printf("\x1b[31m[DEBUG]\x1b[0m : %s ", text);
    if ((long long int)adress != -1) {
        my_printf(" Adress : %p", (long long int)adress);
    }
    my_putchar('c');
}