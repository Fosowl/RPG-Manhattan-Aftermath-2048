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
    if (pos.x >= 200 && pos.x <= 717 && pos.y >= 590 && pos.y <= 700) {
        return (1);
    }
    if (pos.x >= 1100 && pos.x <= 1390 && pos.y >= 890 && pos.y <= 990) {
        return (2);
    }
    if (pos.x >= 1100 && pos.x <= 1635 && pos.y >= 590 && pos.y <= 700) {
        return (3);
    }
    if (pos.x >= 200 && pos.x <= 910 && pos.y >= 890 && pos.y <= 990) {
        return (4);
    }
    return (0);
}

void init_hover_pos(hover_t *hover)
{
    hover->play_pos.x = 200;
    hover->play_pos.y = 500;
    hover->quit_pos.x = 1100;
    hover->quit_pos.y = 800;
    hover->load_pos.x = 1100;
    hover->load_pos.y = 500;
    hover->how_pos.x = 200;
    hover->how_pos.y = 800;
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