/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** destroy_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"

void destroy_inventory(game_t *game)
{
    for (int i = 0; i != 40; i++) {
        sfTexture_destroy(game->inventory->element[i].init->texture);
        sfSprite_destroy(game->inventory->element[i].init->sprite);
        if (game->inventory->element[i].destroy == 1) {
            sfTexture_destroy(game->inventory->element[i].object->texture);
            sfSprite_destroy(game->inventory->element[i].object->sprite);
            game->inventory->element[i].destroy = 0;
        }
        sfText_destroy(game->inventory->element[i].number);
    }
}