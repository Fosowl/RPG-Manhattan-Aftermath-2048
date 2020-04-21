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

static entities_t *create_zombie_scene(entities_t *entities, int zombie)
{
    int x = 0;
    int y = 0;
    entities_t *tmp = NULL;
    char *name = NULL;

    for (int i = 0; i < zombie; i++) {
        name = my_itoa(i);
        entities = starset_entities_add(entities, ZOMBIE_PATH
        , append("zombie:", name), false);
        tmp = starset_entities_get_propreties(entities, name);
        for ( ; starset_get_distance(tmp->position, v_2f{400, 900}) < 300 ; ) {
            x = rand() % 1000;
            y = rand() % 1000;
            starset_entities_teleport(entities, name, x, y);
        }
    }
    return (entities);
}

entities_t *load_entities_scene(int zombie)
{
    entities_t *entities = NULL;

    entities = create_zombie_scene(entities, zombie);
    entities = starset_entities_add(entities, PLAYER_PATH, "player", false);
    if (!entities)
        return (NULL);
    set_zombie_animation(entities);
    set_zombie_sound(entities, zombie);
    set_player_animation(entities);
    set_player_sound(entities);
    starset_entities_teleport(entities, "player", 400, 900);
    starset_entities_get_propreties(entities, "player")->speed = 3;
    return (entities);
}