/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** create_info_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"

basic_object_t *init_info(inventory_t *inventory, int i)
{
    if (inventory->element[i].destroy_info == 1) {
        sfTexture_destroy(inventory->element[i].info->texture);
        sfSprite_destroy(inventory->element[i].info->sprite);
        inventory->element[i].destroy_info = 0;
    }
    if (inventory->element[i].nb > 0) {
        inventory->element[i].info->texture = sfTexture_createFromFile
                                    (info_arms_option(inventory, i), NULL);
        inventory->element[i].info->sprite = sfSprite_create();
        sfSprite_setTexture(inventory->element[i].info->sprite,
                                    inventory->element[i].info->texture, 1);
        inventory->element[i].info->vector.x = 1250;
        inventory->element[i].info->vector.y = 450;
        sfSprite_setPosition(inventory->element[i].info->sprite,
                                        inventory->element[i].info->vector);
        inventory->element[i].destroy_info = 1;
    }
    return (inventory->element[i].info);
}
