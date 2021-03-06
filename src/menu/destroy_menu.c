/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** destroy_menu.c
*/

#include "dependancies.h"
#include "game_struct.h"
#include "menu.h"

void destroy_how_to_play(how_t *how_to)
{
    sfSprite_destroy(how_to->how_bg_sprite);
    sfTexture_destroy(how_to->how_bg_texture);
    sfSprite_destroy(how_to->press_space_sprite);
    sfTexture_destroy(how_to->press_space_texture);
}

void destroy_hover(hover_t *hover)
{
    sfSprite_destroy(hover->play_sprite);
    sfTexture_destroy(hover->play_texture);
    sfSprite_destroy(hover->quit_sprite);
    sfTexture_destroy(hover->quit_texture);
    sfSprite_destroy(hover->load_sprite);
    sfTexture_destroy(hover->load_texture);
    sfSprite_destroy(hover->how_sprite);
    sfTexture_destroy(hover->how_texture);
}

void destroy_menu(game_t *game)
{
    sfSprite_destroy(game->menu->menu_sprite);
    sfTexture_destroy(game->menu->menu_texture);
    sfSprite_destroy(game->menu->play_sprite);
    sfTexture_destroy(game->menu->play_texture);
    sfSprite_destroy(game->menu->quit_sprite);
    sfTexture_destroy(game->menu->quit_texture);
    sfSprite_destroy(game->menu->load_sprite);
    sfTexture_destroy(game->menu->load_texture);
    sfSprite_destroy(game->menu->how_sprite);
    sfTexture_destroy(game->menu->how_texture);
    destroy_hover(game->menu->hover_menu);
    destroy_how_to_play(game->menu->how_to);
}