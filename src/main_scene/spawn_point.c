/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** spawn_point
*/

#include "starset_engine.h"
#include "scene.h"
#include "game_macro.h"

sfVector2f *zombie_spawn_point(int nb_zombie)
{
    sfVector2f *spawn = malloc(sizeof(sfVector2f) * nb_zombie);
    for (int i = 0; i < nb_zombie; i++) {
        spawn[i].x = rand() % 6000;
        spawn[i].y = rand() % 900 - rand() % 2000;
    }
    return (spawn);
}