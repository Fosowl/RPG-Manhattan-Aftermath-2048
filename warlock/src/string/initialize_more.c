/*
** EPITECH PROJECT, 2019
** Makefile
** File description:
** Makefile
*/

#include "warlock.h"

/*
\fn char **clean_double_alloc(int y, int x)
\brief allocate array of string in desirated size.
\param y : the number of string
\param x : the lenght of each string
\return a new array of string(char **).
*/

char **clean_double_alloc(int y, int x)
{
    char **double_buffer = NULL;

    double_buffer = malloc(sizeof(char *) * (y + 1));
    if (double_buffer == NULL) {
        put_error("allocation error !\n");
        return (NULL);
    }
    for (int i = 0; i < y; i++) {
        double_buffer[i] = NULL;
        double_buffer[i] = clean_alloc(x);
        if (double_buffer[i] == NULL) {
            put_error("allocation error !\n");
            return (NULL);
        }
    }
    double_buffer[y] = NULL;
    return (double_buffer);
}
