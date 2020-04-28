/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** malloc_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"

int malloc_element(inventory_t *inventory)
{
    inventory->element = malloc(sizeof(element_inventory_t) * (40));
    if (inventory->element == NULL)
        return (84);
    for (int i = 0; i != 40; i++) {
        inventory->element[i].init = malloc(sizeof(basic_object_t) * (40));
        if (inventory->element[i].init == NULL)
            return (84);
        inventory->element[i].number = malloc(sizeof(sfText *) * (40));
        if (inventory->element[i].number == NULL)
            return (84);
    }
    return (0);
}

int malloc_inventory(game_t *game)
{
    game->inventory = malloc(sizeof(inventory_t));
    if (game->inventory == NULL)
        return (84);
    game->inventory->button_all = malloc(sizeof(basic_object_t));
    if (game->inventory->button_all == NULL)
        return (84);
    if (malloc_element(game->inventory) == 84)
        return (84);
    return (0);
}