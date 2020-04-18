/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** set_player_anim
*/

#include "starset_engine.h"
#include "scene.h"

void set_player_animation(entities_t *entities)
{
    starset_add_animation(entities, "player", "static", (sfVector2u){100, 100});
    set_player_key_static(entities);
    starset_add_animation(entities, "player", "move", (sfVector2u){100, 100});
    set_player_key_move(entities);
    starset_add_animation(entities, "player", "pistol", (sfVector2u){100, 100});
    set_player_key_knife(entities);
    starset_add_animation(entities, "player", "rifle", (sfVector2u){100, 100});
    set_player_key_rifle(entities);
}

void set_player_key_static(entities_t *entities)
{

}

void set_player_key_move(entities_t *entities)
{

}

void set_player_key_knife(entities_t *entities)
{

}

void set_player_key_rifle(entities_t *entities)
{

}