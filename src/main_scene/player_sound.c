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


    if (game->player.save->life < 40 && pass == 0) {
        game->player.ear_off = true;
        starset_entities_play_sound(game->entities_list, "player", "heart", false);
        pass = 1;
    } else if (pass == 1 && game->player.save->life >= 40) {
        game->player.ear_off = false;
        pass = 0;
    }
}