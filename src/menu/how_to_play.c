/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** how_to_play.c
*/

#include "dependancies.h"
#include "menu.h"
#include "scene.h"

void init_how_to_play(menu_t *menu)
{
    menu->how_to->how_bg_texture = sfTexture_createFromFile(
    "assets/menu/how_to_play.png", NULL);
    menu->how_to->how_bg_sprite = sfSprite_create();
    sfSprite_setTexture(menu->how_to->how_bg_sprite,
    menu->how_to->how_bg_texture, sfTrue);
}

void how_to_play(game_t *game)
{
    while (!sfKeyboard_isKeyPressed(sfKeySpace)) {
        sfRenderWindow_drawSprite(game->screen->window,
        game->menu->how_to->how_bg_sprite, NULL);
        sfRenderWindow_display(game->screen->window);
    }
}