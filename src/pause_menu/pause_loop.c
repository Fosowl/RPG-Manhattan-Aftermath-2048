/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** pause_loop.c
*/

#include "dependancies.h"
#include "menu.h"
#include "scene.h"

int check_pause_button(game_t *game)
{
    sfVector2i size = sfMouse_getPositionRenderWindow(game->screen->window);

    if (size.x >= 790 && size.x <= 1120 && size.y >= 350 && size.y <= 440) {
        return (1);
    }
    return (0);
}

void display_pause(game_t *game)
{
    sfRenderWindow_drawSprite(game->screen->window,
    game->menu->pause_m->bg_sprite, NULL);
    sfRenderWindow_drawSprite(game->screen->window,
    game->menu->pause_m->continue_sprite, NULL);
    sfRenderWindow_drawSprite(game->screen->window,
    game->menu->pause_m->quit_game_sprite, NULL);
    sfRenderWindow_display(game->screen->window);
}

static int in_pause_loop(game_t *game, sfEvent event)
{
    int check_click = 0;
    sfVector2i size = sfMouse_getPositionRenderWindow(game->screen->window);

    while (sfRenderWindow_pollEvent(game->screen->window, &event)) {
        if ((event.type == sfEvtMouseButtonReleased)
        && (size.x >= 790 && size.x <= 1120 && size.y >= 350 && size.y <= 440)) {
            check_click = check_pause_button(game);
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyP)) {
        check_click = 1;
    }
    if (check_click == 1) {
        return (1);
    } else if (check_click == 2) {
        return (2);
    }
    return (0);
}

int pause_loop(game_t *game)
{
    sfEvent event;
    int r = 0;
    int hover = 0;

    init_pause(game->menu->pause_m);
    while (r == 0) {
        r = in_pause_loop(game, event);
        if (r != 0)
            return (r);
        display_pause(game);
    }
    destroy_pause(game->menu->pause_m);
    return (1);
}