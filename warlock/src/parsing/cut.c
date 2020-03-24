/*
** EPITECH PROJECT, 2020
** cut.c
** File description:
** cutting function
*/

#include "warlock.h"

/*
\fn char *cut_tail(char *buffer, char character)
\brief cut string tail from delimated character.
\param buffer : string to cut.
\param character : character to delimitate the cut.
\return (char *) the new string cutted.
*/

char *cut_tail(char *buffer, char character)
{
    int occurence = 0;
    int index = 0;
    int count = 0;
    char *tail = clean_alloc(my_strlen(buffer));

    if (DEBUG_MODE == 1)
        debug_log("cut_tail()", buffer);
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == character || buffer[i] == '\t')
            occurence++;
    for (; buffer[index] != '\0'; index++) {
        if (count == occurence)
            break;
        if (buffer[index] == character || buffer[index] == '\t')
            count++;
    }
    for (int i = 0; buffer[index] != '\0'; index++, i++)
        tail[i] = buffer[index];
    return (tail);
}

/*
\fn char *keep_until(char *buffer, char character)
\brief cut string
\param buffer : string to cut.
\param character : character to delimitate the cut.
\return (char *) the new string cutted.
*/

char *keep_until(char *buffer, char character)
{
    int o = 0;
    int index = 0;
    int count = 0;
    char *keep = clean_alloc(my_strlen(buffer));

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == character)
            count++;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == character)
            o++;
        if (o == count) {
            index = i;
            break;
        }
    }
    for (int i = 0; buffer[i] != '\0' && i < index; i++)
        keep[i] = buffer[i];
    return (keep);
}

