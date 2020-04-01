/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** screen
*/

#include "../include/render.h"

int outside_screen(sfVector2f position, float x, float y)
{
    int outside = 0;

    if (position.x > x || position.x < 0)
        outside = 1;
    if (position.y > y || position.y < 0)
        outside = 1;
    return (outside);
}