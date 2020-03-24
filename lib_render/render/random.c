/*
** EPITECH PROJECT, 2019
** generator.c
** File description:
** function to generate stuff like random number
*/

#include "render.h"

int real_random(int max, sfClock *clock)
{
    int random = 0;

    srand((int)sfTime_asSeconds(sfClock_getElapsedTime(clock)));
    random = rand() % max;
    if (random < 0)
        random *= -1;
    return (random);
}