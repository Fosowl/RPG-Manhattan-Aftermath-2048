/*
** EPITECH PROJECT, 2020
** buffer_info.c
** File description:
** function to get info about buffer
*/

#include "warlock.h"

/*
\fn int count_word(char *buffer)
\brief count number of word in a string.
\param buffer : the string in witch you want ot count the number of word.
\return the number of word in the string.
*/

int count_word(char *buffer)
{
    int count = 0;

    if (DEBUG_MODE == 1)
        debug_log("count word", buffer);
    for (int i = 0; buffer[i] != '\0'; i++) {
        for (; buffer[i + 1] == ' ' || buffer[i + 1] == '\t'; i++);
        if (buffer[i] == ' ' || buffer[i] == '\t')
            count++;
    }
    return (count);
}

/*
\fn int longest_word(char *buffer)
\brief return size of longest word in the string
\param buffer : the string in witch you cant to lenght of the longest word.
\return the lenght of the longest word in the string.
*/

int longest_word(char *buffer)
{
    int longest = 0;
    int temp = 0;

    if (DEBUG_MODE == 1)
        debug_log("longest word()", buffer);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != ' ' && buffer[i] != '\t')
            temp++;
        else {
            if (temp > longest)
                longest = temp;
            temp = 0;
        }
    }
    if (temp > longest)
        longest = temp;
    return (longest);
}