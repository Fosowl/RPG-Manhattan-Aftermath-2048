/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** toggle_object
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "warlock.h"

void player_switch_object(entities_t *entities, player_t player, sfEvent *event)
{
    if (sfKeyboard_isKeyPressed(player.control.key_weapon[0])) {
        free(player.selected);
        player.selected = fill("knife");
        starset_entities_get_propreties(entities, "player")->speed = 5;
    }
    if (sfKeyboard_isKeyPressed(player.control.key_weapon[1])) {
        free(player.selected);
        player.selected = fill("pistol");
        starset_entities_get_propreties(entities, "player")->speed = 4;
    }
    if (sfKeyboard_isKeyPressed(player.control.key_weapon[2])) {
        free(player.selected);
        player.selected = fill("rifle");
        starset_entities_get_propreties(entities, "player")->speed = 3;
    }
    if (sfKeyboard_isKeyPressed(player.control.key_weapon[3])) {
        free(player.selected);
        player.selected = fill("torch");
        starset_entities_get_propreties(entities, "player")->speed = 5;
    }
}