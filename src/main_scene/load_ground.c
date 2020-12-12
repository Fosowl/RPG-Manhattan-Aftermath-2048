    /*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** load_ground
*/

#include "starset_engine.h"
#include "warlock.h"
#include "scene.h"
#include "path.h"
#include "game_macro.h"
#include "render.h"

static entities_t *add_each_ground(int r, entities_t *entities)
{
    if (r == 0)
        entities = starset_entities_add(entities, GRASS_1_PATH
        , "map:grass_a", true);
    if (r == 1)
        entities = starset_entities_add(entities, GRASS_2_PATH
        , "map:grass_b", true);
    if (r == 2)
        entities = starset_entities_add(entities, GRASS_3_PATH
        , "map:grass_c", true);
    if (r >= 3)
        entities = starset_entities_add(entities, BLOOD_1_PATH
        , "map:blood_a", true);
    return (entities);
}

entities_t *load_ground(entities_t *entities, int nb)
{
    int r = 0;
    entities_t *tmp = NULL;

    for (int i = 0; i < nb; i++) {
        r = rand() % 4;
        entities = add_each_ground(r, entities);
    }
    while ((tmp = starset_get_next(entities, "map"))) {
        srand((long long int)tmp % RAND_MAX);
        tmp->is_trigger = true;
        tmp->spot.x = (float)(rand() % 3000);
        tmp->spot.y = (float)(rand() % 3000 - 2080);
        tmp->angle = (float)(rand() % 360);
    }
    return (entities);
}
