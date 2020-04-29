/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** player_sound
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "game_macro.h"

void handle_player_sound(game_t *game)
{
    static int pass = 0;

    if (game->player.save->life < 40) {
        game->player.ear_off = true;
        starset_entities_play_sound(game->entities_list, "player", "heart", false);
        pass = 1;
    } else if (pass == 1 && game->player.save->life >= 40) {
        game->player.ear_off = false;
        pass = 0;
    }
}

void handle_zombie_sound(game_t *game)
{
    entities_t *tmp = NULL;
    int volume = 5;
    int distance;

    while((tmp = starset_get_next(game->entities_list, "zombie"))) {
        if (!tmp->control.timer)
            tmp->control.timer = sfClock_create();
        tmp->control.delay = sfClock_getElapsedTime(tmp->control.timer);
        if (sfTime_asMilliseconds(tmp->control.delay) / 1000 < tmp->control.wait)
            continue;
        starset_entities_play_sound(tmp, tmp->name, "breath", false);
        distance = starset_get_distance(tmp->spot
        , game->player.save->spot);
        if (distance < 700)
            volume = (1 - (distance / 700)) * 7;
        else
            volume = 0;
        starset_set_sound_volume(tmp, tmp->name, "breath", volume);
        sfClock_restart(tmp->control.timer);
        tmp->control.wait = rand() % 35;
    }
}