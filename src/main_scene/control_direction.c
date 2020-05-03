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

int teleport_player_up(entities_t *entities, entities_t *save
, entities_t *ground)
{
    entities_t *tmp = NULL;

    if (save->collision && save->collision->spot.y + 30 < save->spot.y) {
        if (search("map:", save->collision->name) != -1 &&
        save->collision->is_trigger == 0)
            return (1);
    }
    for (tmp = entities; tmp != NULL; tmp = tmp->next) {
        if (!(search("player", tmp->name) != -1)) {
            tmp->spot.y += save->speed;
        }
    }
    for (tmp = ground; tmp != NULL; tmp = tmp->next) {
        tmp->spot.y += save->speed;
    }
    return (1);
}

int teleport_player_down(entities_t *entities, entities_t *save
, entities_t *ground)
{
    entities_t *tmp = NULL;

    if (save->collision && save->collision->spot.y - 30 > save->spot.y) {
        if (search("map:", save->collision->name) != -1 &&
        save->collision->is_trigger == 0)
            return (1);
    }
    for (tmp = entities; tmp != NULL; tmp = tmp->next) {
        if (!(search("player", tmp->name) != -1)) {
            tmp->spot.y -= save->speed;
        }
    }
    for (tmp = ground; tmp != NULL; tmp = tmp->next) {
        tmp->spot.y -= save->speed;
    }
    return (1);
}

int teleport_player_left(entities_t *entities, entities_t *save
, entities_t *ground)
{
    entities_t *tmp = NULL;

    if (save->collision && save->collision->spot.x + 30 < save->spot.x) {
        if (search("map:", save->collision->name) != -1 &&
        save->collision->is_trigger == 0)
            return (1);
    }
    for (tmp = entities; tmp != NULL; tmp = tmp->next) {
        if (!(search("player", tmp->name) != -1)) {
            tmp->spot.x += save->speed;
        }
    }
    for (tmp = ground; tmp != NULL; tmp = tmp->next) {
        tmp->spot.x += save->speed;
    }
    return (1);
}

int teleport_player_right(entities_t *entities, entities_t *save
, entities_t *ground)
{
    entities_t *tmp = NULL;

    if (save->collision && save->collision->spot.x - 30 > save->spot.x) {
        if (search("map:", save->collision->name) != -1 &&
        save->collision->is_trigger == 0)
            return (1);
    }
    for (tmp = entities; tmp != NULL; tmp = tmp->next) {
        if (!(search("player", tmp->name) != -1) &&
        save->collision_vector.x <= 0) {
            tmp->spot.x -= save->speed;
        }
    }
    for (tmp = ground; tmp != NULL; tmp = tmp->next) {
        tmp->spot.x -= save->speed;
    }
    return (1);
}