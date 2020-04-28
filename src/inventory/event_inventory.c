/*
** EPITECH PROJECT, 2019
** rpg_en_cours
** File description:
** event_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"

void event_button_inventory(game_t *game)
{
    sfVector2i pos_mouse;
    sfVector2f pos_bag;
    sfVector2f rec_bag;

    pos_mouse = sfMouse_getPositionRenderWindow(game->window);
    pos_bag = sfSprite_getPosition(game->inventory->button_all->sprite);
    rec_bag.x = pos_bag.x + 139;
    rec_bag.y = pos_bag.y + 169;
    if ((pos_mouse.x >= pos_bag.x && pos_mouse.x <= rec_bag.x
        && pos_mouse.y >= pos_bag.y && pos_mouse.y <= rec_bag.y)
        && (game->inventory->button == 1))
        game->inventory->button = 0;
    else if (pos_mouse.x >= pos_bag.x && pos_mouse.x <= rec_bag.x
        && pos_mouse.y >= pos_bag.y && pos_mouse.y <= rec_bag.y)
        game->inventory->button = 1;
}