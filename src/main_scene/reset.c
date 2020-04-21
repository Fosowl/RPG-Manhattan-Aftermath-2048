/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** reset
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "game_macro.h"

void reset_value(game_t *game)
{
    starset_reset_value(&game->player.noise, 5.0f, 1.0f);
}