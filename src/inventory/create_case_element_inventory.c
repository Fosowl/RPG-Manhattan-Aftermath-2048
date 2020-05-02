/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** inventory.c
*/

#include "game_struct.h"
#include "inventory.h"
#include "time.h"

basic_object_t *init_case_element(inventory_t *inventory, int i, int x, int y)
{
    inventory->element[i].init->texture = sfTexture_createFromFile
                                            ("assets/inventory/case.png", NULL);
    inventory->element[i].init->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->element[i].init->sprite,
                                        inventory->element[i].init->texture, 1);
    inventory->element[i].init->vector.x = x;
    inventory->element[i].init->vector.y = y;
    sfSprite_setPosition(inventory->element[i].init->sprite,
                                            inventory->element[i].init->vector);
    return (inventory->element[i].init);
}

void create_case(inventory_t *inventory, int width)
{
    int length = 0;
    static int i = 0;
    int all = 8 + i;
    sfVector2f nb_element = {0, width + 5};

    for (; i != all; i++) {
        inventory->element[i].init = init_case_element(inventory, i,
                                                        460.5 + length, width);
        inventory->element[i].object = init_element(inventory, i,
                                                        461 + length, width);
        length += 95;
        nb_element.x = 372 + length;
        sfText_setPosition(inventory->element[i].number, nb_element);
        sfText_setCharacterSize(inventory->element[i].number, 20);
        sfText_setString(inventory->element[i].number,
                                        my_itoa_e(inventory->element[i].nb));
    }
}

void create_case_element(inventory_t *inventory)
{
    element_for_start(inventory);
    create_move(inventory);
    create_button_inventory(inventory);
    create_nb_element(inventory);
    create_case(inventory, 900);
    create_case(inventory, 800);
    create_case(inventory, 705);
    create_case(inventory, 610);
    create_case(inventory, 515);
}

void display_case_element(game_t *game)
{
    for (int i = 0; i != 8; i++) {
        sfRenderWindow_drawSprite(game->window,
                                game->inventory->element[i].init->sprite, NULL);
        display_nb_element(game, i);
        display_element(game, i);
    }
    sfRenderWindow_drawSprite(game->window,
                                    game->inventory->button_all->sprite, NULL);
    if (game->inventory->button == 1) {
        for (int i = 8; i != 40; i++) {
            sfRenderWindow_drawSprite(game->window,
                                game->inventory->element[i].init->sprite, NULL);
            display_nb_element(game, i);
            display_element(game, i);
        }
    }
}