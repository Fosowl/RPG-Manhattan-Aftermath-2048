/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** set_zombie_anim
*/

#include "starset_engine.h"
#include "scene.h"
#include "game_macro.h"

void set_zombie_animation(entities_t *entities)
{
    starset_add_animation(entities, "zombie", "static"
    , (sfVector2u){80, 80});
    starset_add_animation(entities, "zombie", "move", (sfVector2u){80, 90});
    starset_add_animation(entities, "zombie", "attack"
    , (sfVector2u){80, 80});
    set_zombie_key_static(entities);
    set_zombie_key_move(entities);
    set_zombie_key_attack(entities);
}

void set_zombie_key_static(entities_t *entities)
{
    add_key(entities, "zombie", "static", (sfVector2f){423, 0});
    add_key(entities, "zombie", "static", (sfVector2f){500, 0});
    add_key(entities, "zombie", "static", (sfVector2f){580, 0});
    add_key(entities, "zombie", "static", (sfVector2f){660, 0});
    add_key(entities, "zombie", "static", (sfVector2f){734, 0});
    add_key(entities, "zombie", "static", (sfVector2f){818, 0});
    add_key(entities, "zombie", "static", (sfVector2f){900, 0});
    add_key(entities, "zombie", "static", (sfVector2f){977, 0});
    add_key(entities, "zombie", "static", (sfVector2f){1062, 0});
}

void set_zombie_key_move(entities_t *entities)
{
    add_key(entities, "zombie", "move", (sfVector2f){1142, 18});
    add_key(entities, "zombie", "move", (sfVector2f){1238, 14});
    add_key(entities, "zombie", "move", (sfVector2f){1335, 8});
}

void set_zombie_key_attack(entities_t *entities)
{
    add_key(entities, "zombie", "attack", (sfVector2f){17, 5});
    add_key(entities, "zombie", "attack", (sfVector2f){116, 5});
    add_key(entities, "zombie", "attack", (sfVector2f){231, 5});
    add_key(entities, "zombie", "attack", (sfVector2f){329, 5});
}