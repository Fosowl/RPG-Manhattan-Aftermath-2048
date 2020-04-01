/*
** EPITECH PROJECT, 2020
** render_lib
** File description:
** time
*/

#include "../include/render.h"

void my_sleep(int wait)
{
    static struct sfClock *delay;
    static sfTime timeUnit;

    delay = sfClock_create();
    while (1) {
        timeUnit = sfClock_getElapsedTime(delay);
        if (timeUnit.microseconds >= wait) {
            break;
        }
    }
}