/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** set_sound
*/

#include "starset_engine.h"
#include "game_macro.h"
#include "warlock.h"

void set_zombie_sound(entities_t *entities, int nb_zombie)
{
    char *str = NULL;

    for (int i = 0; i < nb_zombie; i++) {
        str = my_itoa(i);
        if (rand() % 2 == 1) {
            starset_add_entities_sound(entities, str, "breath"
            , "assets/audio/zombie_moan.ogg");
        } else {
            starset_add_entities_sound(entities, str, "breath"
            , "assets/audio/zombie_talking.ogg");
            starset_entities_get_propreties(entities, str)->audio->volume = 99;
        }
    }
    starset_add_entities_sound(entities, "zombie", "death"
    , "assets/audio/zombie_death.ogg");
    starset_add_entities_sound(entities, "zombie", "pain"
    , "assets/audio/zombie_pain.ogg");
}

void set_player_sound(entities_t *entities)
{
    starset_add_entities_sound(entities, "player", "pain"
    , "assets/audio/pain.ogg");
    starset_add_entities_sound(entities, "player", "heart"
    , "assets/audio/heart.ogg");
    starset_add_entities_sound(entities, "player", "gun"
    , "assets/audio/gun.ogg");
    starset_add_entities_sound(entities, "player", "rifle"
    , "assets/audio/rifle.ogg");
    starset_add_entities_sound(entities, "player", "collide"
    , "assets/audio/bang.ogg");
}