/*
** EPITECH PROJECT, 2019
** replace.c
** File description:
** usefull3 function
*/

#include "warlock.h"


// sub-function of replace

static void save_tail(int r, char *str, char *tail, char *this)
{
    int i = 0;

    while (str[r] == this[i]) {
        r++;
        i++;
    }
    i = 0;
    while (str[r] != '\0') {
        tail[i] = str[r];
        i++;
        r++;
    }
    tail[i] = '\0';
}

// sub-function of replace

static void add_tail_and_word(char *replaced, char *tail, char *this)
{
    int i = 0;
    int k = 0;

    while (replaced[i] != '\0')
        i++;
    for (k = 0; this[k] != '\0'; k++) {
        replaced[i] = this[k];
        i++;
    }
    for (k = 0; tail[k] != '\0'; k++) {
        replaced[i] = tail[k];
        i++;
    }
    replaced[i] = '\0';
}

char *replace(char *str, char *this, char *with)
{
    int found = 0;
    char *replaced = clean_alloc(sizeof(char) * (my_strlen(str)
    + my_strlen(with)) + 2);
    char *tail = clean_alloc(sizeof(char) * my_strlen(str) + 2);

    DEBUG_MODE == 1 ? debug_log("replace() first arg", str) : 0;
    while (found != -1) {
        found = search(this, str) - 1;
        save_tail(found + my_strlen(this) + 1, str, tail, this);
        for (int t = 0; t <= found; t++) {
            replaced[t] = str[t];
            replaced[t + 1] = '\0';
        }
        add_tail_and_word(replaced, tail, with);
        break;
    }
    free (tail);
    return (replaced);
}