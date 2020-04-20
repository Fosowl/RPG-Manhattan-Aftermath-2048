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

static int switch_animation(player_t *player, int *r)
{
    char *animation = NULL;

    if (*r == 2) {
        animation = append(player->selected, ":attack");
        *r = starset_play_animation(player->save, "player", animation, 3);
        if (*r == 1)
            *r = 2;
        return (7);
    }
    if (*r == 3) {
        animation = append(player->selected, ":reload");
        *r = starset_play_animation(player->save, "player", animation, 3);
        if (*r == 1)
            *r = 3;
        return (7);
    }
    return (1);
}

int attack_entities(player_t *player, sfEvent *event
, sfRenderWindow *window)
{
    static int r = 0;

    if (event->mouseButton.button == sfMouseLeft && !compare(player->selected
    , "torch")) {
        starset_single_play_sound(player->save, player->selected, false);
        r = 2;
        event->mouseButton.button = -1;
    }
    if (event->mouseButton.button == sfMouseRight && !(compare(player->selected
    , "torch") || compare(player->selected, "knife"))) {
        starset_single_play_sound(player->save, "reload", false);
        r = 3;
        event->mouseButton.button = -1;
    }
    return (switch_animation(player, &r));
}