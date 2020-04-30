/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** load_entities into scene
*/

#include "starset_engine.h"
#include "warlock.h"
#include "scene.h"
#include "path.h"
#include "game_macro.h"
#include "render.h"

static void set_propreties(entities_t *entities)
{
    starset_entities_teleport(entities, "player", 400, 900);
    starset_entities_teleport(entities, "sora", 1500, 300);
    starset_entities_get_propreties(entities, "player")->speed = 3;
    starset_entities_get_propreties(entities, "sora")->life = 300;
}

static entities_t *load_object(entities_t *entities)
{
    entities_t *blood = NULL;

    entities = starset_entities_add(entities, DOG_PATH, "dog", false);
    entities = starset_entities_add(entities, GIRL_PATH, "sora", false);
    entities = starset_entities_add(entities, BULLET_PATH
    , "bullet_2", false);
    entities = starset_entities_add(entities, BULLET_PATH
    , "bullet_1", false);
    entities = starset_entities_add(entities, BLOOD_PATH, "blood", true);
    blood = starset_entities_get_propreties(entities, "blood");
    starset_add_animation(blood, "blood", "simple", (sfVector2u){41, 49});
    starset_add_animation_key(blood, "blood", "simple", (sfVector2f){105.0f, 101.0f});
    starset_play_animation(blood, "blood", "simple", 1);
    blood->is_trigger = true;
    return (entities);
}

static entities_t *load_building(entities_t *entities)
{
   return (entities);
}

entities_t *load_entities_scene(int zombie, sfRenderWindow *window)
{
    entities_t *entities = NULL;

    sfRenderWindow_clear(window, sfBlack);
    draw_loading_text(window);
    entities = load_building(entities);
    entities = create_zombie_scene(entities, zombie, window);
    entities = starset_entities_add(entities, PLAYER_PATH, "player", false);
    entities = load_object(entities);
    set_dog(entities);
    set_zombie_animation(entities);
    set_zombie_sound(entities, zombie);
    set_player_animation(entities);
    set_player_sound(entities);
    set_girl_animation(entities);
    set_girl_sound(entities);
    set_propreties(entities);
    return (entities);
}
