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

void update_object(game_t *game)
{
    entities_t *bullet = NULL;

    bullet = starset_entities_get_propreties(game->entities_list, "bullet");
    if (bullet->visible == true) {
        starset_move_from_angle(bullet, "bullet", bullet->angle, 20);
        if (starset_get_distance(bullet->position
        , game->player.save->position) > 900) {
            bullet->visible = false;
            bullet->position.x = -100.0f;
            bullet->position.y = -100.0f;
        }
    }
}