/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** hover_display.c
*/

#include "dependancies.h"
#include "menu.h"
#include "scene.h"

int hover_menu_text(game_t *game)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);

    if (pos.x >= 150 && pos.x <= 544 && pos.y >= 530 && pos.y <= 624) {
        return (1);
    }
    if (pos.x >= 1650 && pos.x <= 1855 && pos.y >= 100 && pos.y <= 188) {
        return (2);
    }
    if (pos.x >= 150 && pos.x <= 545 && pos.y >= 825 && pos.y <= 925) {
        return (3);
    }
    if (pos.x >= 1300 && pos.x <= 1799 && pos.y >= 675 && pos.y <= 770) {
        return (4);
    }
    return (0);
}

void init_hover_pos(hover_t *hover)
{
    hover->play_pos.x = 150;
    hover->play_pos.y = 500;
    hover->quit_pos.x = 1650;
    hover->quit_pos.y = 75;
    hover->load_pos.x = 140;
    hover->load_pos.y = 795;
    hover->how_pos.x = 1300;
    hover->how_pos.y = 650;
}

void init_hover(hover_t *hover)
{
    hover->play_texture = sfTexture_createFromFile(
    "assets/menu/hover_new.png", NULL);
    hover->play_sprite = sfSprite_create();
    sfSprite_setTexture(hover->play_sprite, hover->play_texture, sfTrue);
    sfSprite_setPosition(hover->play_sprite, hover->play_pos);
    hover->quit_texture = sfTexture_createFromFile(
    "assets/menu/hover_quit.png", NULL);
    hover->quit_sprite = sfSprite_create();
    sfSprite_setTexture(hover->quit_sprite, hover->quit_texture, sfTrue);
    sfSprite_setPosition(hover->quit_sprite, hover->quit_pos);
    hover->load_texture = sfTexture_createFromFile(
    "assets/menu/hover_load.png", NULL);
    hover->load_sprite = sfSprite_create();
    sfSprite_setTexture(hover->load_sprite, hover->load_texture, sfTrue);
    sfSprite_setPosition(hover->load_sprite, hover->load_pos);
    hover->how_texture = sfTexture_createFromFile("assets/menu/hover_how.png",
    NULL);
    hover->how_sprite = sfSprite_create();
    sfSprite_setTexture(hover->how_sprite, hover->how_texture, sfTrue);
    sfSprite_setPosition(hover->how_sprite, hover->how_pos);
}

void display_hover_menu(game_t *game, int hover)
{
    if (hover == 1) {
        sfRenderWindow_drawSprite(game->screen->window,
        game->menu->hover_menu->play_sprite, NULL);
    }
    if (hover == 2) {
        sfRenderWindow_drawSprite(game->screen->window,
        game->menu->hover_menu->quit_sprite, NULL);
    }
    if (hover == 3) {
        sfRenderWindow_drawSprite(game->screen->window,
        game->menu->hover_menu->load_sprite, NULL);
    }
    if (hover == 4)
        sfRenderWindow_drawSprite(game->screen->window,
        game->menu->hover_menu->how_sprite, NULL);
}