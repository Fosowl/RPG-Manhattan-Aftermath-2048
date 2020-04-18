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

entities_t *load_entities_scene(int zombie)
{
    entities_t *entities = NULL;
    char *name = NULL;
    int x = 0;
    int y = 0;

    for (int i = 0; i < zombie; i++) {
        name = my_itoa(i);
        entities = starset_entities_add(entities, ZOMBIE_PATH
        , append("zombie:", name), false);
        starset_entities_teleport(entities, name, x, y);
    }
    set_zombie_animation(entities);
    set_player_animation(entities);
    entities = starset_entities_add(entities, PLAYER_PATH, "player", false);
    if (!entities)
        return (NULL);
    return (entities);
}