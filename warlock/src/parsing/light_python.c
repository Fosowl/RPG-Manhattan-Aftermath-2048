/*
** EPITECH PROJECT, 2019
** light_python.c
** File description:
** python fu like but in C
*/

#include "warlock.h"

char *append(char *origin, char *added)
{
    char *fusioned = NULL;
    int d = 0;

    DEBUG_MODE == 1 ? debug_log("append() first arg", origin) : 0;
    DEBUG_MODE == 1 ? debug_log("append() second arg", added) : 0;
    fusioned = malloc(sizeof(char *) * (my_strlen(origin)
        + my_strlen(added) + 1));
    if (!fusioned)
        return (NULL);
    for (d = 0; origin != NULL && origin[d] != '\0'; d++)
        fusioned[d] = origin[d];
    for (int i = 0; added != NULL && added[i] != '\0'; i++, d++)
        fusioned[d] = added[i];
    fusioned[d] = '\0';
    return (fusioned);
}

char *pop(char *origin, char character)
{
    char *copy = NULL;
    int occurence = 0;

    DEBUG_MODE == 1 ? debug_log("pop() first arg", origin) : 0;
    if (!origin)
        return (NULL);
    for (int c = 0; origin[c]; c++)
        if (origin[c] == character)
            occurence++;
    copy = malloc(sizeof(char *) * (my_strlen(origin) - occurence) + 1);
    if (copy == NULL)
        return (NULL);
    for (int i = 0, d = 0; origin[i] != '\0'; i++, d++) {
        if (origin[i] == character)
            i++;
        copy[d] = origin[i];
    }
    return (copy);
}
