/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** info_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"

char *info_care_option(inventory_t *inventory, int i, char *path)
{
    switch (inventory->element[i].type)
    {
    case 10:
        path = "assets/inventory/info_bandage.png";
        break;
    case 11:
        path = "assets/inventory/info_medicalkit.png";
        break;
    }
    return (path);
}

char *info_food_option(inventory_t *inventory, int i, char *path)
{
    switch (inventory->element[i].type)
    {
    case 7:
        path = "assets/inventory/info_water.png";
        break;
    case 8:
        path = "assets/inventory/info_canned.png";
        break;
    case 9:
        path = "assets/inventory/info_apple.png";
        break;
    default:
        path = info_care_option(inventory, i, path);
        break;
    }
    return (path);
}

char *info_bullet_option(inventory_t *inventory, int i, char *path)
{
    switch (inventory->element[i].type)
    {
    case 4:
        path = "assets/inventory/info_bullet1.png";
        break;
    case 5:
        path = "assets/inventory/info_bullet2.png";
        break;
    case 6:
        path = "assets/inventory/info_steak.png";
        break;
    default:
        path = info_food_option(inventory, i, path);
        break;
    }
    return (path);
}

char *info_arms_option(inventory_t *inventory, int i)
{
    char *path = NULL;

    switch (inventory->element[i].type)
    {
    case 1:
        path = "assets/inventory/info_ak47.png";
        break;
    case 2:
        path = "assets/inventory/info_knife.png";
        break;
    case 3:
        path = "assets/inventory/info_gun.png";
        break;
    default:
        path = info_bullet_option(inventory, i, path);
        break;
    }
    return (path);
}
