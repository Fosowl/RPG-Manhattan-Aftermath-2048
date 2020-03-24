/*
** EPITECH PROJECT, 2020
** array.c
** File description:
** array of string manipulation
*/

#include "warlock.h"

/*
\fn int locate_array_element(char **p, char *keyword)
\brief determine the position of a string in an array
of string according to a corresponding keyword.
\param p : array of string to search in.
\param keyboard : keyword to find in the array.
\return the index in the array of string.
*/

int locate_array_element(char **p, char *keyword)
{
    int o = 0;

    DEBUG_MODE == 1 ? debug_log("locate_array_element()", p) : 0;
    DEBUG_MODE == 1 ? debug_log("locate_array_element", keyword) : 0;
    for (o = 0; p[o] != NULL; o++) {
        if (search(keyword, p[o]) == 0)
            break;
    }
    return (o);
}