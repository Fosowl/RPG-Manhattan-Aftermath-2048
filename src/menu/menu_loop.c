/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** menu_loop.c
*/

#include "dependancies.h"
#include "menu.h"
#include "scene.h"

int check_press(sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (pos.x >= 107 && pos.x <= 476 && pos.y >= 338 && pos.y <= 400) {
        return (1);
    }
    if (pos.x >= 716 && pos.x <= 890 && pos.y >= 314 && pos.y <= 375) {
        return (2);
    }
    if (pos.x >= 102 && pos.x <= 470 && pos.y >= 521 && pos.y <= 580) {
        return (3);
    }
    if (pos.x >= 700 && pos.x <= 1180 && pos.y >= 510 && pos.y <= 575) {
        return (4);
    }
    return (0);
}

void display_menu(game_t *game, int hover)
{
    sfRenderWindow_clear(game->screen->window, sfBlack);
    sfRenderWindow_drawSprite(game->screen->window, game->menu->menu_sprite,
    NULL);
    if (hover != 1) {
        sfRenderWindow_drawSprite(game->screen->window, game->menu->play_sprite,
        NULL);
    }
    if (hover != 2) {
        sfRenderWindow_drawSprite(game->screen->window, game->menu->quit_sprite,
        NULL);
    }
    if (hover != 3) {
        sfRenderWindow_drawSprite(game->screen->window, game->menu->load_sprite,
        NULL);
    }
    if (hover != 4)
        sfRenderWindow_drawSprite(game->screen->window, game->menu->how_sprite,
        NULL);
    display_hover_menu(game, hover);
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
        check_click = check_press(game->screen->window);
    if (check_click == 1) {
        sfSound_stop(game->menu->menu_music);
        if (main_scene_load(game) == 0) {
            return (0);
        }
        return (1);
    } else if (check_click == 2) {
        sfSound_destroy(game->menu->menu_music);
        destroy_menu(game);
        return (2);
    }
    if (check_click == 4)
        return (how_to_play(game, event));
    return (0);
}

int menu_loop(game_t *game)
{
    sfEvent event;
    int r = 0;
    int hover = 0;

    init_screen(game->screen);
    init_menu(game->menu);
    while (starset_running(game->screen->window, &event) && r != 9) {
        game->window_pos = sfRenderWindow_getPosition(game->screen->window);
        game->mouse_pos = sfMouse_getPositionRenderWindow(game->screen->window);
        r = in_menu_loop(game, event);
        hover = hover_menu_text(game);
        if (r != 0)
            return (r);
        display_menu(game, hover);
    }
    close_menu_screen(game->screen->window, event);
    sfSound_stop(game->menu->menu_music);
    destroy_menu(game);
    return (0);
}
