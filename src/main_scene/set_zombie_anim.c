/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** set_zombie_anim
*/

#include "starset_engine.h"
#include "scene.h"

void set_zombie_animation(entities_t *entities)
{
    starset_add_animation(entities, "zombie", "static", (sfVector2u){100, 100});
    starset_add_animation(entities, "zombie", "move", (sfVector2u){100, 100});
    starset_add_animation(entities, "zombie", "attack"
    , (sfVector2u){100, 100});
    set_zombie_key_static(entities);
    set_zombie_key_move(entities);
    set_zombie_key_attack(entities);
}

void set_zombie_key_static(entities_t *entities)
{
    starset_add_animation_key(entities, "zombie", "static"
    , (sfVector2f){400, 100});
    starset_add_animation_key(entities, "zombie", "static"
    , (sfVector2f){500, 100});
    starset_add_animation_key(entities, "zombie", "static"
    , (sfVector2f){600, 100});
    starset_add_animation_key(entities, "zombie", "static"
    , (sfVector2f){700, 100});
    starset_add_animation_key(entities, "zombie", "static"
    , (sfVector2f){800, 100});
    starset_add_animation_key(entities, "zombie", "static"
    , (sfVector2f){1000, 100});
    starset_add_animation_key(entities, "zombie", "static"
    , (sfVector2f){1100, 100});
    starset_add_animation_key(entities, "zombie", "static"
    , (sfVector2f){1200, 100});
    starset_add_animation_key(entities, "zombie", "static"
    , (sfVector2f){1300, 100});
}

void set_zombie_key_move(entities_t *entities)
{
    starset_add_animation_key(entities, "zombie", "move"
    , (sfVector2f){1400, 100});
    starset_add_animation_key(entities, "zombie", "move"
    , (sfVector2f){1500, 100});
    starset_add_animation_key(entities, "zombie", "move"
    , (sfVector2f){1600, 100});
    starset_add_animation_key(entities, "zombie", "move"
    , (sfVector2f){1700, 100});
    starset_add_animation_key(entities, "zombie", "move"
    , (sfVector2f){1800, 100});
    starset_add_animation_key(entities, "zombie", "move"
    , (sfVector2f){1900, 100});
}

void set_zombie_key_attack(entities_t *entities)
{
    starset_add_animation_key(entities, "zombie", "attack"
    , (sfVector2f){0, 100});
    starset_add_animation_key(entities, "zombie", "attack"
    , (sfVector2f){100, 100});
    starset_add_animation_key(entities, "zombie", "attack"
    , (sfVector2f){200, 100});
    starset_add_animation_key(entities, "zombie", "attack"
    , (sfVector2f){300, 100});
}