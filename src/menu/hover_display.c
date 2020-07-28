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
    sfVector2i pos = game->mouse_pos;

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

void init_hover_pos(hover_t *hover)
{
    hover->play_pos.x = 93.75;
    hover->play_pos.y = 312.5;
    hover->quit_pos.x = 700;
    hover->quit_pos.y = 300;
    hover->load_pos.x = 93;
    hover->load_pos.y = 500;
    hover->how_pos.x = 700;
    hover->how_pos.y = 500; 
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