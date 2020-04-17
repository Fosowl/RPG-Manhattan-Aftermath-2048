/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** init_struct.c
*/

#include "dependancies.h"
#include "menu.h"

void init_struct(game_t *game)
{
    game->screen = malloc(sizeof(screen_t));
    game->menu = malloc(sizeof(menu_t));
}