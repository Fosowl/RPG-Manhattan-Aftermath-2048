/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** girl_ai
*/

#include "game_struct.h"
#include "inventory.h"
#include "scene.h"
#include "starset_engine.h"
#include "render.h"
#include "game_macro.h"
#include "warlock.h"

void girl_ai(game_t *game)
{
    starset_play_animation(game->entities_list, "sora", "pistol:move", 4);
}