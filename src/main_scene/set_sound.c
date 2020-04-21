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
        srand(i);
        if (rand() % 2 == 1) {
            starset_add_entities_sound(entities, str, "breath"
            , "assets/audio/zombie_moan.ogg");
            starset_set_sound_volume(entities, str, "breath", 5);
        } else {
            starset_add_entities_sound(entities, str, "breath"
            , "assets/audio/zombie_talking.ogg");
            starset_set_sound_volume(entities, str, "breath", 100);
        }
    }
    starset_add_entities_sound(entities, "zombie", "death"
    , "assets/audio/zombie_death.ogg");
    starset_add_entities_sound(entities, "zombie", "pain"
    , "assets/audio/zombie_pain.ogg");
}

void set_player_sound(entities_t *entities)
{
    entities_t *player = starset_entities_get_propreties(entities, "player");

    starset_add_entities_sound(player, "player", "pain"
    , "assets/audio/pain.ogg");
    starset_add_entities_sound(player, "player", "heart"
    , "assets/audio/heart.ogg");
    starset_add_entities_sound(player, "player", "pistol"
    , "assets/audio/gun.ogg");
    starset_add_entities_sound(player, "player", "rifle"
    , "assets/audio/rifle.ogg");
    starset_add_entities_sound(player, "player", "collide"
    , "assets/audio/bang.ogg");
    starset_add_entities_sound(player, "player", "reload"
    , "assets/audio/reload.ogg");
    starset_add_entities_sound(player, "player", "knife"
    , "assets/audio/knife.ogg");
    starset_set_sound_volume(player, "player", "pain", 70);
    starset_set_sound_volume(player, "player", "heart", 100);
    starset_set_sound_volume(player, "player", "pistol", 100);
    starset_set_sound_volume(player, "player", "rifle", 100);
    starset_set_sound_volume(player, "player", "collide", 70);
    starset_set_sound_volume(player, "player", "reload", 80);
    starset_set_sound_volume(player, "player", "knife", 100);
}