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

static int in_menu_loop(game_t *game, sfEvent event)
{
    int check_click = 0;

    if (event.type == sfEvtMouseButtonPressed)
        check_click = check_press(event);
    if (check_click == 1) {
        sfSound_destroy(game->menu->menu_music);
        main_scene_load(game);
        return (1);
    } else if (check_click == 2) {
        sfSound_destroy(game->menu->menu_music);
        destroy_menu(game);
        return (2);
    }
    return (0);
}

int menu_loop(game_t *game)
{
    sfEvent event;
    int r = 0;

    init_screen(game->screen);
    init_menu(game->menu);
    while (starset_running(game->screen->window, &event)) {
        r = in_menu_loop(game, event);
        if (r != 0)
            return (r);
        display_menu(game);
    }
    close_menu_screen(game->screen->window, event);
    destroy_menu(game);
    return (0);
}