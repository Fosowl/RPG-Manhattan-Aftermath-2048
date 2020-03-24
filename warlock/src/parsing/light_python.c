/*
** EPITECH PROJECT, 2019
** light_python.c
** File description:
** python fu like but in C
*/

#include "warlock.h"

/*
\fn char *append(char *origin, char *added)
\brief insert string in front of another with clean memory usage.
\param origin : (char *) first string to increase.
\param added : (char *) string to add at end of first string.
\return (char *) new string that result in the 2 string combinated.
*/

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
    if (origin)
        free(origin);
    return (fusioned);
}

/*
\fn char *pop(char *origin, char character);
\brief pop character occurence in string
\param origin : (char *) string to modify.
\param character : (char) character to pop.
\return (char *) new string with character occurence removed.
*/

char *pop(char *origin, char character)
{
    char *copy = NULL;
    int occurence = 0;

    DEBUG_MODE == 1 ? debug_log("pop() first arg", origin) : 0;
    if (!origin)
        return NULL;
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
    free(origin);
    return (copy);
}
