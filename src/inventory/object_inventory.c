/*
** EPITECH PROJECT, 2019
** rpg_en_cours
** File description:
** object_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"

sfTexture *object_care_option(inventory_t *inventory, int i)
{
    switch (inventory->element[i].type)
    {
    case 10:
        option_texture = sfTexture_createFromFile
                                        ("assets/inventory/care1.png", NULL);
        break;
    case 11:
        option_texture = sfTexture_createFromFile
                                        ("assets/inventory/care2.png", NULL);
        break;
    }
    return (option_texture);
}

sfTexture *object_food_option(inventory_t *inventory, int i)
{
    switch (inventory->element[i].type)
    {
    case 7:
        option_texture = sfTexture_createFromFile
                                            ("assets/inventory/eat2.png", NULL);
        break;
    case 8:
        option_texture = sfTexture_createFromFile
                                            ("assets/inventory/eat3.png", NULL);
        break;
    case 9:
        option_texture = sfTexture_createFromFile
                                            ("assets/inventory/eat4.png", NULL);
        break;
    default:
        option_texture = object_care_option(inventory, i);
        break;
    }
    return (option_texture);
}

sfTexture *object_bullet_option(inventory_t *inventory, int i)
{
    switch (inventory->element[i].type)
    {
    case 4:
        option_texture = sfTexture_createFromFile
                                        ("assets/inventory/bullet1.png", NULL);
        break;
    case 5:
        option_texture = sfTexture_createFromFile
                                        ("assets/inventory/bullet2.png", NULL);
        break;
    case 6:
        option_texture = sfTexture_createFromFile
                                        ("assets/inventory/eat1.png", NULL);
        break;
    default:
        option_texture = object_food_option(inventory, i);
        break;
    }
    return (option_texture);
}

void type_of_object(inventory_t *inventory, int i)
{
    if (inventory->element[i].type >= 10 && inventory->element[i].type <= 11)
        inventory->element[i].class = 4;
    if (inventory->element[i].type >= 7 && inventory->element[i].type <= 9)
        inventory->element[i].class = 3;
    if (inventory->element[i].type >= 4 && inventory->element[i].type <= 6)
        inventory->element[i].class = 2;
    if (inventory->element[i].type >= 1 && inventory->element[i].type <= 3)
        inventory->element[i].class = 1;
}

sfTexture *object_arms_option(inventory_t *inventory, int i)
{
    type_of_object(inventory, i);
    switch (inventory->element[i].type)
    {
    case 1:
        option_texture = sfTexture_createFromFile
                                            ("assets/inventory/ak47.png", NULL);
        break;
    case 2:
        option_texture = sfTexture_createFromFile
                                        ("assets/inventory/knife.png", NULL);
        break;
    case 3:
        option_texture = sfTexture_createFromFile
                                            ("assets/inventory/gun.png", NULL);
        break;
    default:
        option_texture = object_bullet_option(inventory, i);
        break;
    }
    return (option_texture);
}
