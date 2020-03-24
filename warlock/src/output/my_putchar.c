/*
** EPITECH PROJECT, 2018
** my_putchar.c
** File description:
** put char
*/

#include "warlock.h"

/*
\fn void my_putchar(char c)
\brief function to put one character on the
standard output
\param c : the character to print on standart output.
\return 0.
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}