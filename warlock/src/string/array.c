/*
** EPITECH PROJECT, 2020
** array.c
** File description:
** array of string manipulation
*/

#include "warlock.h"

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

char **array_add_element(char **array, char *element)
{
    char **copy = NULL;
    int height = 0;

    for (height = 0; array[height] != NULL; height++);
    copy = clean_double_alloc(height + 2, 300);
    copy_double(copy, array);
    free(array);
    copy[height] = fill(element);
    copy[height + 1] = NULL;
    return (copy);
}

char **array_pop_element(char **array, int this)
{
    char **copy = NULL;
    int height = 0;
    int o = 0;
    int i = 0;

    for (height = 0; array[height]; height++);
    copy = clean_double_alloc(height, 300);
    while (o < height) {
        if (o == this) {
            o++;
            continue;
        }
        for (i = 0; array[o][i] != '\0'; i++)
            copy[o][i] = array[o][i];
        copy[o][i] = '\0';
        o++;
    }
    copy[height - 1] = NULL;
    free (array);
    return (copy);
}