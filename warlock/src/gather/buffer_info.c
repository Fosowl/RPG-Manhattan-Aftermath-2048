/*
** EPITECH PROJECT, 2020
** buffer_info.c
** File description:
** function to get info about buffer
*/

#include "warlock.h"

int count_word(char *buffer, char separation)
{
    int count = 0;

    if (DEBUG_MODE == 1)
        debug_log("count word", buffer);
    for (int i = 0; buffer[i] != '\0'; i++) {
        for (; buffer[i + 1] == separation || buffer[i + 1] == '\t'; i++);
        if (buffer[i] == separation || buffer[i] == '\t')
            count++;
    }
    return (count);
}

int longest_word(char *buffer, char separation)
{
    int longest = 0;
    int temp = 0;

    if (DEBUG_MODE == 1)
        debug_log("longest word()", buffer);
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != separation && buffer[i] != '\t')
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