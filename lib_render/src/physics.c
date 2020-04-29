/*
** EPITECH PROJECT, 2019
** physics.c
** File description:
** reproduce physics like gravity, wind ...
*/

#include "../include/render.h"

void simulate_wind(object_t *object, float direction, int force)
{
    sfVector2f add_force;

    if (object->weight <= 0)
        object->weight = 1;
    add_force.x = 2 * cos(direction) * (force / object->weight);
    add_force.y = 2 * sin(180 - (direction + 90)) * (force / object->weight);
    object->spot.y += add_force.y;
    object->spot.x += add_force.x;
}

