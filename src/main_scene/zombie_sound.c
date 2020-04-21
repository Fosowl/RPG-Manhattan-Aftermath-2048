/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** zombie_sound
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "render.h"
#include "game_macro.h"
#include "warlock.h"

void handle_zombie_sound(game_t *game)
{
    static sfClock *timer = NULL;
    sfTime delay;
    static int r = 2;

    if (!timer)
        timer = sfClock_create();
    delay = sfClock_getElapsedTime(timer);
    if (sfTime_asMilliseconds(delay) / 1000 < r)
        return;
    starset_entities_play_sound(game->entities_list, "zombie", "breath", true);
    sfClock_restart(timer);
    r = rand() % 10;
}