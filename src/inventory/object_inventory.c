/*
** EPITECH PROJECT, 2019
** rpg_en_cours
** File description:
** object_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"

char *object_care_option(inventory_t *inventory, int i, char *path)
{
    switch (inventory->element[i].type)
    {
    case 10:
        path = "assets/inventory/care1.png";
        break;
    case 11:
        path = "assets/inventory/care2.png";
        break;
    }
    return (path);
}

char *object_food_option(inventory_t *inventory, int i, char *path)
{
    switch (inventory->element[i].type)
    {
    case 7:
        path = "assets/inventory/eat2.png";
        break;
    case 8:
        path = "assets/inventory/eat3.png";
        break;
    case 9:
        path = "assets/inventory/eat4.png";
        break;
    default:
        path = object_care_option(inventory, i, path);
        break;
    }
    return (path);
}

char *object_bullet_option(inventory_t *inventory, int i, char *path)
{
    switch (inventory->element[i].type)
    {
    case 4:
        path = "assets/inventory/bullet1.png";
        break;
    case 5:
        path = "assets/inventory/bullet2.png";
        break;
    case 6:
        path = "assets/inventory/eat1.png";
        break;
    default:
        path = object_food_option(inventory, i, path);
        break;
    }
    return (path);
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

char *object_arms_option(inventory_t *inventory, int i)
{
    char *path = NULL;

    type_of_object(inventory, i);
    switch (inventory->element[i].type)
    {
    case 1:
        path = "assets/inventory/ak47.png";
        break;
    case 2:
        path = "assets/inventory/knife.png";
        break;
    case 3:
        path = "assets/inventory/gun.png";
        break;
    default:
        path = object_bullet_option(inventory, i, path);
        break;
    }
    return (path);
}
