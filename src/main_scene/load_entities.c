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
    entities_t *tmp = NULL;

    starset_entities_teleport(entities, "player", 400, 900);
    starset_entities_teleport(entities, "sora", 1500, 300);
    starset_entities_get_propreties(entities, "player")->speed = 3;
    starset_entities_get_propreties(entities, "sora")->life = 300;
}

static entities_t *load_object(entities_t *entities)
{
    entities = load_pick_object(entities, 10);
    entities = starset_entities_add(entities, DOG_PATH, "dog", false);
    entities = starset_entities_add(entities, GIRL_PATH, "sora", false);
    entities = starset_entities_add(entities, BULLET_PATH
    , "bullet_2", false);
    entities = starset_entities_add(entities, BULLET_PATH
    , "bullet_1", false);
    entities = starset_entities_add(entities, BULLET_PATH
    , "bullet_1", false);
    return (entities);
}

static entities_t *load_building(entities_t *entities)
{
    entities = load_ground(entities, 10);
    entities = load_map(entities);
    return (entities);
}

entities_t *load_entities_scene(int zombie, sfRenderWindow *window)
{
    entities_t *entities = NULL;

    sfRenderWindow_clear(window, sfBlack);
    draw_loading_text(window);
    entities = load_building(entities);
    entities = load_object(entities);
    //entities = create_zombie_scene(entities, zombie, window);
    entities = starset_entities_add(entities, PLAYER_PATH, "player", false);
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
