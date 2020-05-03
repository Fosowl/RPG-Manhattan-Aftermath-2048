/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** set_sound
*/

#include "starset_engine.h"
#include "game_macro.h"
#include "warlock.h"
#include "path.h"

void set_zombie_sound(entities_t *entities, int nb_zombie)
{
    char *str = NULL;

    for (int i = 0; i < nb_zombie; i++) {
        str = my_itoa(i);
        srand(i);
        if (rand() % 2 == 1) {
            starset_add_entities_sound(entities, str, "breath", MOAN_PATH);
            starset_set_sound_volume(entities, str, "breath", 5);
        } else {
            starset_add_entities_sound(entities, str, "breath", TALK_PATH);
            starset_set_sound_volume(entities, str, "breath", 100);
        }
    }
    starset_add_entities_sound(entities, "zombie", "death", ZOMBIE_DEATH_PATH);
    starset_add_entities_sound(entities, "zombie", "pain", ZOMBIE_PAIN_PATH);
}

void set_player_sound(entities_t *entities)
{
    entities_t *player = starset_entities_get_propreties(entities, "player");

    starset_add_entities_sound(player, "player", "pain", PLAYER_PAIN_PATH);
    starset_add_entities_sound(player, "player", "heart", HEARTH_PATH);
    starset_add_entities_sound(player, "player", "pistol", PISTOL_SOUND_PATH);
    starset_add_entities_sound(player, "player", "rifle", RIFLE_SOUND_PATH);
    starset_add_entities_sound(player, "player", "yes", YES_SOUND);
    starset_add_entities_sound(player, "player", "reload", RELOAD_SOUND);
    starset_add_entities_sound(player, "player", "knife", KNIFE_SOUND);
    starset_add_entities_sound(player, "player", "empty", EMPTY_SOUND);
    starset_set_sound_volume(player, "player", "pain", 70);
    starset_set_sound_volume(player, "player", "heart", 100);
    starset_set_sound_volume(player, "player", "pistol", 100);
    starset_set_sound_volume(player, "player", "rifle", 100);
    starset_set_sound_volume(player, "player", "collide", 70);
    starset_set_sound_volume(player, "player", "reload", 80);
    starset_set_sound_volume(player, "player", "knife", 100);
}

void set_girl_sound(entities_t *entities)
{
    entities_t *player = starset_entities_get_propreties(entities, "sora");

    starset_add_entities_sound(player, "sora", "pain", PLAYER_PAIN_PATH);
    starset_add_entities_sound(player, "sora", "pistol", PISTOL_SOUND_PATH);
    starset_set_sound_volume(player, "sora", "pain", 80);
    starset_set_sound_volume(player, "sora", "pistol", 90);
    starset_set_sound_volume(player, "sora", "collide", 70);
    sfSound_setPitch(player->audio->sound, 1.4);
}