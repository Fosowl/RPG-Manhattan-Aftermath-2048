/*
** EPITECH PROJECT, 2019
** rpg_en_cours
** File description:
** update_nb_object.c
*/

#include "game_struct.h"
#include "inventory.h"

void check_nb_for_class(inventory_t *inventory, int i, int max)
{
    if (inventory->element[i].nb > max) {
        inventory->element[i].status = 3;
    }
    if (inventory->element[i].nb == 0) {
        inventory->element[i].status = 0;
    }
    if (inventory->element[i].nb == max) {
        inventory->element[i].status = 2;
    } else if (inventory->element[i].nb > 0 && inventory->element[i].nb < max) {
        inventory->element[i].status = 1;
    }
}

void option_for_class(inventory_t *inventory, int i)
{
    switch (inventory->element[i].class)
    {
    case 1:
        if (inventory->element[i].nb == 1)
            inventory->element[i].status = 2;
        else if (inventory->element[i].nb < 1)
            inventory->element[i].status = 0;
        break;
    case 2:
        check_nb_for_class(inventory, i, 10);
        break;
    case 3:
        check_nb_for_class(inventory, i, 5);
        break;
    case 4:
        check_nb_for_class(inventory, i, 5);
        break;
    }
}

void check_inventory_full(inventory_t *inventory)
{
    int full = 0;

    for (int a = 0; a != 40; a++)
        if (inventory->element[a].status == 2
                                        || inventory->element[a].status == 3)
            full++;
    if (full == 36) {
        my_printf("INVENTORY FULL\n");
        return;
    }
}

void already_exists(inventory_t *inventory, int i)
{
    int size = 0;
    int stock = 0;

    for (int k = 0; k != 40; k++) {
        if (inventory->element[k].type == inventory->element[i].type) {
            size += inventory->element[k].nb;
        }
    }
    if (size == inventory->contains[i].nb) {
    } else if (size != inventory->contains[i].nb) {
        for (; inventory->element[stock].status != 1
            && inventory->element[stock].type == inventory->element[i].type
                                                        && stock < 40; stock++)
        inventory->element[stock].nb += inventory->contains[i].nb - size;
    }
}

void new_value_contains(inventory_t *inventory)
{
    int new_case = 0;

    check_inventory_full(inventory);
    for (int i = 0; i != 11; i++) {
        if (inventory->contains[i].nb > 0
                                        && inventory->contains[i].status == 1) {
            already_exists(inventory, i);
        } else if (inventory->contains[i].nb > 0
                                        && inventory->contains[i].status != 1) {
            for (; inventory->element[new_case].status != 0 && i < 40;
                                                                    new_case++);
            inventory->element[new_case].status = 1;
            inventory->element[new_case].type = i + 1;
            inventory->element[new_case].nb = inventory->contains[i].nb;
            inventory->contains[i].status = 1;
        }
    }
}