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

    if (x >= 150 && x <= 544 && y >= 530 && y <= 624) {
        return (1);
    }
    if (x >= 1650 && x <= 1855 && y >= 100 && y <= 188) {
        return (2);
    }
    if (x >= 150 && x <= 545 && y >= 825 && y <= 925) {
        return (3);
    }
    if (x >= 1300 && x <= 1799 && y >= 675 && y <= 770) {
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