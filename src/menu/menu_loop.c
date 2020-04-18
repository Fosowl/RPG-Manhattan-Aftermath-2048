/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** menu_loop.c
*/

#include "dependancies.h"
#include "menu.h"
#include "scene.h"

int check_press(sfEvent event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    if (x >= 400 && x <= 739 && y >= 800 && y <= 968) {
        return (1);
    }
    if (x >= 1100 && x <= 1483 && y >= 800 && y <= 969) {
        return (2);
    }
    return (0);
}

void display_menu(game_t *game)
{
        sfRenderWindow_clear(game->screen->window, sfBlack);
        sfRenderWindow_drawSprite(game->screen->window, game->menu->menu_sprite,
        NULL);
        sfRenderWindow_drawSprite(game->screen->window, game->menu->play_sprite,
        NULL);
        sfRenderWindow_drawSprite(game->screen->window, game->menu->quit_sprite,
        NULL);
        sfRenderWindow_display(game->screen->window);
}

void close_menu_screen(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

int menu_loop(game_t *game)
{
    int check_click = 0;
    sfEvent event;

    init_screen(game->screen);
    init_menu(game->menu);
    while (sfRenderWindow_isOpen(game->screen->window)) {
        while (sfRenderWindow_pollEvent(game->screen->window, &event));
        if (event.type == sfEvtMouseButtonPressed) {
            check_click = check_press(event);
        }
        if (check_click == 1) {
            main_scene_load(game);
            return (1);
        } else if (check_click == 2) {
            destroy_menu(game);
            return (2);
        }
        display_menu(game);
    }
    close_menu_screen(game->screen->window, event);
    destroy_menu(game);
    return (0);
}