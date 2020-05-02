/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** dog_anim
*/

#include "starset_engine.h"
#include "scene.h"
#include "game_macro.h"

void set_dog(entities_t *entities)
{
    entities_t *dog = starset_entities_get_propreties(entities, "dog");

    starset_add_animation(dog, "dog", "move", (sfVector2u){23, 56});
    starset_add_animation_key(dog, "dog", "move"
    , (sfVector2f){165.0f, 134.0f});
    starset_add_animation_key(dog, "dog", "move"
    , (sfVector2f){197.0f, 134.0f});
    starset_add_animation_key(dog, "dog", "move"
    , (sfVector2f){229.0f, 134.0f});
    starset_add_animation_key(dog, "dog", "move"
    , (sfVector2f){261.0f, 134.0f});
    dog->speed = 3;
    dog->spot.x = 400.0f;
    dog->spot.y = 300.0f;
}

void move_dog(entities_t *entities, entities_t *player, sfVector2f girl)
{
    static entities_t *dog = NULL;
    static sfVector2f target;
    int distance = 0;

    if (!dog)
        dog = starset_entities_get_propreties(entities, "dog");
    if (!player || !dog)
        return;
    distance = starset_get_distance(dog->spot, player->spot);
    if (distance < 230) {
        target = girl;
    } else if (distance > 600) {
        target.x = player->spot.x;
        target.y = player->spot.y;
    }
    dog->aspect->rotation = 90;
    starset_entities_move(dog, "dog", target.x, target.y);
    if (distance > 240) {
        starset_play_animation(dog, "dog", "move", 10);
        starset_entities_rotate_to(dog, "dog", target);
    }
}