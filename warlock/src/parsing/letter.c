/*
** EPITECH PROJECT, 2019
** letter.c
** File description:
** letter
*/

#include "warlock.h"

/*
\fn char *empty_string(char *str)
\brief init an empty string
\param str : (char *) string to init.
\return NULL if string is NULL
*/

char *empty_string(char *str)
{
    if (DEBUG_MODE == 1)
        debug_log("empty_string()", str);
    if (!str)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = '\0';
    return str;
}

/*
\fn char *insert(char *str, char pushed)
\brief insert character at beginning of string.
\param str : (char *) string to insert the character in.
\return (char *) string with character inserted.
*/

char *insert(char *str, char pushed)
{
    char *increased = NULL;
    int i;

    if (DEBUG_MODE == 1)
        debug_log("insert()", str);
    if (!str)
        return NULL;
    increased = malloc(sizeof(char) * (my_strlen(str) + 2));
    if (!increased)
        return NULL;
    increased[0] = pushed;
    for (i = 0; str[i] != '\0'; i++)
        increased[i + 1] = str[i];
    increased[i + 1] = '\0';
    free(str);
    return increased;
}

/*
\fn char *capitalize(char *str)
\brief capitalize a string.
\param str : (char *) string to capitalize.
\return (char *) new copy in capital letter.
*/

char *capitalize(char *str)
{
    if (DEBUG_MODE == 1)
        debug_log("capitalize()", str);
    if (!str)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
    return str;
}
