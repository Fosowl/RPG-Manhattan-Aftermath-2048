/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** init_struct.c
*/

#include "dependancies.h"
#include "menu.h"
#include "game_struct.h"
#include "inventory.h"

int init_struct(game_t *game)
{
    game->screen = malloc(sizeof(screen_t));
    if (game->screen == NULL)
        return (84);
    game->menu = malloc(sizeof(menu_t));
    if (game->menu == NULL)
        return (84);
    game->menu->hover_menu = malloc(sizeof(hover_t));
    if (game->menu->hover_menu == NULL)
        return (84);
    malloc_inventory(game);
    return (0);
}