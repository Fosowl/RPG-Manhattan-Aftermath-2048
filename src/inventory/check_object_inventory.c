/*
** EPITECH PROJECT, 2019
** rpg_en_cours
** File description:
** check_object_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"

void case_is_full(inventory_t *inventory, int i, int type, int new_case)
{
    for (; inventory->element[new_case].status != 0 && i < 40; new_case++);
    type = inventory->element[i].type - 1;
    inventory->element[new_case].status = 1;
    inventory->element[i].status = 2;
    inventory->element[i].nb = inventory->contains[type].max;
    inventory->element[new_case].type = inventory->element[i].type;
    inventory->element[new_case].class = inventory->element[i].class;
    inventory->element[new_case].nb =
    inventory->contains[type].nb % inventory->contains[type].max;
}

void case_is_not_full(inventory_t *inventory, int k, int type, int new_case)
{
    int size = 0;

    for (int x = 0; x != 40; x++) {
        if (inventory->element[x].type == inventory->element[k].type)
            size += inventory->element[x].nb;
    }
    if (size != inventory->contains[type].nb) {
        inventory->element[k].nb += inventory->contains[type].nb - size;
        if (inventory->element[k].nb == inventory->contains[type].max) {
            for (; inventory->element[new_case].status != 0 && new_case < 40;
                                                                new_case++);
            inventory->element[new_case].status = 1;
            inventory->element[new_case].type = inventory->element[k].type;
        }
    }
}

int element_is_full(inventory_t *inventory, int i)
{
    int k = 0;

    for (; k != 40; k++) {
        if (inventory->element[i].type == inventory->element[k].type
            && inventory->element[k].status != 2)
            break;
    }
    return (k);
}

void add_new_value(inventory_t *inventory, int i)
{
    int type = 0;
    int new_case = 0;
    int k = 0;

    option_for_class(inventory, i);
    nb_case_for_type(inventory, i, inventory->element[i].class);
    if (inventory->element[i].status == 3)
        case_is_full(inventory, i, type, new_case);
    else if (inventory->element[i].status == 1) {
        k = element_is_full(inventory, i);
        type = inventory->element[i].type - 1;
        case_is_not_full(inventory, k, type, new_case);
    }
    check_for_draw(inventory, i);
}