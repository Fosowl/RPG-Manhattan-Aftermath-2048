/*
** EPITECH PROJECT, 2019
** rpg_en_cours
** File description:
** update_element.c
*/

#include "game_struct.h"
#include "inventory.h"

void init_items_for_start_of_game(inventory_t *inventory)
{
    inventory->contains[AK47].nb = 1;
    inventory->contains[GUN].nb = 1;
    inventory->contains[KNIFE].nb = 1;
    inventory->contains[BULLET_AK47].nb = 39;
    inventory->contains[BULLET_GUN].nb = 29;
    inventory->contains[STEAK].nb = 19;
    inventory->contains[WATER].nb = 19;
    inventory->contains[APPLE].nb = 19;
    inventory->contains[CANNED].nb = 19;
    inventory->contains[BANDAGE].nb = 19;
    inventory->contains[MEDICAL_KIT].nb = 19;
}

void update_element(game_t *game)
{
    new_value_contains(game->inventory);
    for (int i = 0; i != 40; i++)
        add_new_value(game->inventory, i);
    create_element(game->inventory);
    display_case_element(game);
}

void calc_nb_case(inventory_t *inventory, int i, int max)
{
    int type = inventory->element[i].type - 1;

    inventory->contains[type].max = max;
    if (inventory->contains[type].nb % max != 0)
        inventory->contains[type].nb_case =
                                    (inventory->contains[type].nb / max) + 1;
    else if (inventory->contains[type].nb % max == 0)
        inventory->contains[type].nb_case =
                                        (inventory->contains[type].nb / max);
}

void nb_case_for_type(inventory_t *inventory, int i, int class)
{
    if (class >= 3 && class <= 4)
        calc_nb_case(inventory, i, 5);
    if (class == 2)
        calc_nb_case(inventory, i, 10);
    if (class == 1)
        calc_nb_case(inventory, i, 1);
}