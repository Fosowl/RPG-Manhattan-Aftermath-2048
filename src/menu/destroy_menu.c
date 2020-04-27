/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** destroy_menu.c
*/

#include "dependancies.h"
#include "menu.h"

void destroy_menu(game_t *game)
{
    sfMusic_destroy(game->menu->menu_music);
    sfSprite_destroy(game->menu->menu_sprite);
    sfTexture_destroy(game->menu->menu_texture);
    sfSprite_destroy(game->menu->play_sprite);
    sfTexture_destroy(game->menu->play_texture);
    sfSprite_destroy(game->menu->quit_sprite);
    sfTexture_destroy(game->menu->quit_texture);
}