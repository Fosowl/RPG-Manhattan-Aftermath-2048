/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** update_object
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "render.h"
#include "game_macro.h"
#include "warlock.h"

void reset_value(game_t *game)
{
    starset_reset_value(&game->player.noise, 5.0f, 1.0f);
}

//game->entities_list = starset_entities_destroy(game->entities_list, tmp->name);

void update_object(game_t *game)
{
    entities_t *bullet = NULL;
    entities_t *tmp = NULL;

    bullet = starset_entities_get_propreties(game->entities_list, "bullet");
    if (!bullet)
        return;
    while ((tmp = starset_get_next(game->entities_list, "bullet"))) {
        starset_move_from_angle(tmp, tmp->name, tmp->angle, 20);
        if (starset_get_distance(tmp->spot
        , game->player.save->spot) > 900
        && starset_get_distance(tmp->spot, game->girl->spot) > 700) {
            starset_entities_get_propreties(game->entities_list
            , tmp->name)->life = 0;
            starset_entities_get_propreties(game->entities_list
            , tmp->name)->visible = 0;
            starset_entities_get_propreties(game->entities_list
            , tmp->name)->spot.x = -500.0f;
        }
    }
}