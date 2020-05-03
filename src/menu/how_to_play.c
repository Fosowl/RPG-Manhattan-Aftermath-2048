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
    menu->how_to->press_space_texture = sfTexture_createFromFile(
    "assets/menu/press_space.png", NULL);
    menu->how_to->press_space_sprite = sfSprite_create();
    sfSprite_setTexture(menu->how_to->press_space_sprite,
    menu->how_to->press_space_texture, sfTrue);
    menu->how_to->press_space_pos.x = 20;
    menu->how_to->press_space_pos.y = 800;
    sfSprite_setPosition(menu->how_to->press_space_sprite,
    menu->how_to->press_space_pos);
}

int quit_menu(game_t *game, sfEvent event)
{
    while (sfRenderWindow_pollEvent(game->screen->window, &event)) {
        if (event.type == sfEvtClosed)
            return (9);
    }
    return (0);
}

int how_to_play(game_t *game, sfEvent event)
{
    int i = 0;

    while (!sfKeyboard_isKeyPressed(sfKeySpace) && i == 0) {
        sfRenderWindow_drawSprite(game->screen->window,
                                    game->menu->how_to->how_bg_sprite, NULL);
        sfRenderWindow_drawSprite(game->screen->window,
                                game->menu->how_to->press_space_sprite, NULL);
        sfRenderWindow_display(game->screen->window);
        i = quit_menu(game, event);
    }
    return (i);
}