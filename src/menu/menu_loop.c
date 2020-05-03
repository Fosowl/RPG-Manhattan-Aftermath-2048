/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** menu_loop.c
*/

#include "dependancies.h"
#include "menu.h"
#include "scene.h"

int check_press(sfEvent event, sfRenderWindow *window)
{
    sfVector2i size = sfMouse_getPositionRenderWindow(window);

    if (size.x >= 150 && size.x <= 544 && size.y >= 530 &&
    size.y <= 624) {
        return (1);
    }
    if (size.x >= 1650 && size.x <= 1855 && size.y >= 100 &&
    size.y <= 188) {
        return (2);
    }
    if (size.x >= 150 && size.x <= 545 && size.y >= 825 &&
    size.y <= 925) {
        return (3);
    }
    if (size.x >= 1300 && size.x <= 1799 && size.y >= 675 && size.y <= 770) {
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
        check_click = check_press(event, game->screen->window);
    if (check_click == 1) {
        if (main_scene_load(game) == 0) {
            return (0);
        }
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
    int hover = 0;

    init_screen(game->screen);
    init_menu(game->menu);
    while (starset_running(game->screen->window, &event)) {
        r = in_menu_loop(game, event);
        hover = hover_menu_text(game);
        if (r != 0)
            return (r);
        display_menu(game, hover);
    }
    close_menu_screen(game->screen->window, event);
    destroy_menu(game);
    return (0);
}