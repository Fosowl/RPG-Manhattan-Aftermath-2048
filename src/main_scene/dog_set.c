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
    dog->speed = 4;
    dog->position.x = 400.0f;
    dog->position.y = 300.0f;
}

void move_dog(entities_t *entities, entities_t *player)
{
    static entities_t *dog = NULL;
    static int toggle = 0;

    if (!dog)
        dog = starset_entities_get_propreties(entities, "dog");
    if (starset_get_distance(dog->position, player->position) > 750 ||
    toggle == 0) {
        starset_entities_move(dog, "dog", player->position.x
        , player->position.y);
        toggle = 0;
    } else if (starset_get_distance(dog->position, player->position) < 300) {
        starset_entities_move(dog, "dog", 1500, 300);
        toggle = 1;
    }
}