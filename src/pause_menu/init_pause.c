/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** init_pause.c
*/

#include "dependancies.h"
#include "menu.h"
#include "scene.h"

void init_pos(pause_t *pause_m)
{
    pause_m->bg_pos.x = 362.6;
    pause_m->bg_pos.y = 100;
    pause_m->continue_pos.x = 425;
    pause_m->continue_pos.y = 235;
    pause_m->quit_game_pos.x = 505;
    pause_m->quit_game_pos.y = 375;
}

void init_pause(pause_t *pause_m)
{
    init_pos(pause_m);
    pause_m->bg_texture = sfTexture_createFromFile(
    "assets/menu/pause_menu.jpg", NULL);
    pause_m->bg_sprite = sfSprite_create();
    sfSprite_setTexture(pause_m->bg_sprite,
    pause_m->bg_texture, sfTrue);
    sfSprite_setPosition(pause_m->bg_sprite, pause_m->bg_pos);
    pause_m->continue_texture = sfTexture_createFromFile(
    "assets/menu/cpause.png", NULL);
    pause_m->continue_sprite = sfSprite_create();
    sfSprite_setTexture(pause_m->continue_sprite,
    pause_m->continue_texture, sfTrue);
    sfSprite_setPosition(pause_m->continue_sprite, pause_m->continue_pos);
    pause_m->quit_game_texture = sfTexture_createFromFile(
    "assets/menu/qpause.png", NULL);
    pause_m->quit_game_sprite = sfSprite_create();
    sfSprite_setTexture(pause_m->quit_game_sprite,
    pause_m->quit_game_texture, sfTrue);
    sfSprite_setPosition(pause_m->quit_game_sprite, pause_m->quit_game_pos);
}