/*
** EPITECH PROJECT, 2019
** rpg_en_cours
** File description:
** create_element_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"

basic_object_t *init_element(inventory_t *inventory, int i, int x, int y)
{
    if (inventory->element[i].nb > 0) {
        inventory->element[i].object->texture =
                                            object_arms_option(inventory, i);
        inventory->element[i].object->sprite = sfSprite_create();
        sfSprite_setTexture(inventory->element[i].object->sprite,
                                    inventory->element[i].object->texture, 1);
        inventory->element[i].object->vector.x = x;
        inventory->element[i].object->vector.y = y;
        sfSprite_setPosition(inventory->element[i].object->sprite,
                                        inventory->element[i].object->vector);
    }
    return (inventory->element[i].object);
}

void check_for_draw(inventory_t *inventory, int i)
{
    if (inventory->element[i].nb > 0)
        inventory->element[i].draw = 1;
}

int create_other(inventory_t *inventory, int width, int i)
{
    int length = 0;
    int all = 8 + i;
    sfVector2f nb_element = {0, width + 5};
    for (; i != all; i++) {
        inventory->element[i].object = init_element(inventory, i,
                                                        461 + length, width);
        length += 95;
        nb_element.x = 372 + length;
        sfText_setPosition(inventory->element[i].number, nb_element);
        sfText_setCharacterSize(inventory->element[i].number, 20);
        sfText_setString(inventory->element[i].number,
                                        my_itoa_e(inventory->element[i].nb));
    }
    return (i);
}

void create_element(inventory_t *inventory)
{
    static int i = 0;

    i = create_other(inventory, 900, i);
    i = create_other(inventory, 800, i);
    i = create_other(inventory, 705, i);
    i = create_other(inventory, 610, i);
    i = create_other(inventory, 515, i);
    i = 0;
}

void element_for_start(inventory_t *inventory)
{
    int a = 0;

    for (int i = 0; i != 40; i++) {
        inventory->element[i].draw = 0;
        inventory->element[i].type = 0;
        inventory->element[i].status = 0;
        inventory->element[i].class = 0;
        inventory->element[i].nb = 0;
    }
    init_items_for_start_of_game(inventory);
    for (int i = 0; i != 11; i++) {
        if (inventory->contains[i].nb > 0) {
            inventory->element[a].nb = inventory->contains[i].nb;
            inventory->element[a].type = i + 1;
            inventory->element[a].status = 1;
            type_of_object(inventory, a);
            inventory->contains[i].status = 1;
            a++;
        }
    }
}
