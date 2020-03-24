/*
** EPITECH PROJECT, 2020
** letter_info.c
** File description:
** letter_info
*/

#include "warlock.h"

/*
\fn int compare_letter(char l1, char l2)
\brief compare 2 letter and ignore case.
\param l1 : (char) first character.
\param l2 : (char) second character.
\return 1 if char are same letter and 0 if not the case.
*/

int compare_letter(char l1, char l2)
{
    if (l1 == l2)
        return (1);
    if (l1 >= 97 && l1 <= 122) {
        if (l1 - 32 == l2)
            return (1);
    }
    else {
        if (l1 + 32 == l2)
            return (1);
    }
    return (0);
}

/*
\fn int is_number(char *c)
\brief check if character is a number.
\param c : (char) character to check.
\return 1 if character is a number.
*/

int is_number(char *c)
{
    if (DEBUG_MODE == 1)
        debug_log("is_number()", c);
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] >= 48 && c[i] <= 57)
            continue;
        return (0);
    }
    return (1);
}