/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** screen
*/

#include "../include/render.h"

int outside_screen(sfVector2f spot, float x, float y)
{
    int outside = 0;

    if (spot.x > x || spot.x < 0)
        outside = 1;
    if (spot.y > y || spot.y < 0)
        outside = 1;
    return (outside);
}