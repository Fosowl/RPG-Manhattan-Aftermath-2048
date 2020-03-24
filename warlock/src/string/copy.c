/*
** EPITECH PROJECT, 2020
** copy.c
** File description:
** copy
*/

#include "warlock.h"

/*
\fn int copy_double(char **copy, char **array)
\brief copy an array of string into another.
\param copy : the copied array string.
\param array : the array of string to copy.
\return 0.
*/

int copy_double(char **copy, char **array)
{
    DEBUG_MODE == 1 ? debug_log("copy_double()", copy) : 0;
    DEBUG_MODE == 1 ? debug_log("copy_double()", array) : 0;
    for (int i = 0; array[i] != NULL; i++) {
        for (int k = 0; array[i][k] != '\0'; k++) {
            copy[i][k] = array[i][k];
        }
    }
    return (0);
}

/*
\fn int my_strcpy(char *dest, char *src)
\brief copy a string into another.
\param dest : the copied string
\param src : the string to copy
\return 0.
*/

int my_strcpy(char *dest, char *src)
{
    DEBUG_MODE == 1 ? debug_log("my_strcpy() first arg", dest) : 0;
    DEBUG_MODE == 1 ? debug_log("my_strcpy() second arg", src) : 0;
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return (0);
}