/*
** EPITECH PROJECT, 2020
** count.c
** File description:
** count
*/

#include "warlock.h"

/*
\fn int count_digit(float *number)
\brief count number of digit in a number
\param number : (float *) number to count digit.
\return number of digit in number.
*/

int count_digit(float *number)
{
    int digit = 1;

    if (DEBUG_MODE == 1)
        debug_log("count digit()", number);
    while (*number >= 10) {
        *number = *number / 10;
        digit++;
    }
    return (digit);
}

/*
\fn int array_lenght(char **array)
\brief measure lenght of and array of string
\param array(char **) array to measure the lenght.
\return number of element of the array of string.
*/

int array_lenght(char **array)
{
    int l = 0;

    for (; array[l] != NULL; l++);
    return (l);
}