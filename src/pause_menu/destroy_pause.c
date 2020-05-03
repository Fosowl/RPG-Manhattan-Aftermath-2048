/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** destroy_pause.c
*/

#include "dependancies.h"
#include "menu.h"
#include "scene.h"

void destroy_pause(pause_t *pause_m)
{
    sfSprite_destroy(pause_m->bg_sprite);
    sfTexture_destroy(pause_m->bg_texture);
}
