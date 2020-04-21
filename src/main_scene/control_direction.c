/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** control_direction
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "warlock.h"
#include "game_macro.h"

int teleport_player_up(entities_t *entities, entities_t *save)
{
    starset_entities_teleport(entities, "player"
    , save->position.x, save->position.y - save->speed);
    return (1);
}

int teleport_player_down(entities_t *entities, entities_t *save)
{
    starset_entities_teleport(entities, "player"
    , save->position.x, save->position.y + save->speed);
    return (1);
}

int teleport_player_left(entities_t *entities, entities_t *save)
{
    starset_entities_teleport(entities, "player"
    , save->position.x - save->speed, save->position.y);
    return (1);
}

int teleport_player_right(entities_t *entities, entities_t *save)
{
    starset_entities_teleport(entities, "player"
    , save->position.x + save->speed, save->position.y);
    return (1);
}