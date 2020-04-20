/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** player_attack
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "warlock.h"
#include "game_macro.h"

int attack_entities(player_t *player, sfEvent *event
, sfRenderWindow *window)
{
    char *animation = append(player->selected, ":attack");
    static int r = 0;

    if (event->mouseButton.button == sfMouseLeft && !compare(player->selected
    , "torch")) {
        starset_single_play_sound(player->save, player->selected, false);
        r = 1;
    }
    if (event->mouseButton.button == sfMouseRight && !(compare(player->selected
    , "torch") || compare(player->selected, "knife"))) {
        starset_single_play_sound(player->save, "reload", false);
        r = 2;
    }
    if (r == 1) {
        r = starset_play_animation(player->save, "player", animation, 3);
        return (-100);
    }
    if (r == 2) {
        r = starset_play_animation(player->save, "player", "reload", 3);
        r == 2 ? r = 1 : 0; 
        return (-100);
    }
    return (0);
}