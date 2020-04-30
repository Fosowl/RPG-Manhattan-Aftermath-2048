/*
** EPITECH PROJECT, 2019
** rpg_en_cours
** File description:
** create_button_all.c
*/

#include "game_struct.h"
#include "inventory.h"

void create_button_inventory(inventory_t *inventory)
{
    inventory->button_all->texture = sfTexture_createFromFile
                                            ("assets/inventory/bag.png", NULL);
    inventory->button_all->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->button_all->sprite,
                                        inventory->button_all->texture, 1);
    inventory->button_all->vector.x = 1280;
    inventory->button_all->vector.y = 835;
    sfSprite_setPosition(inventory->button_all->sprite,
                                            inventory->button_all->vector);
}

void create_nb_element(inventory_t *inventory)
{
    sfFont *font;

    for (int i = 0; i != 40; i++) {
        inventory->element[i].number = sfText_create();
        font = sfFont_createFromFile("assets/inventory/11.ttf");
        sfText_setFont(inventory->element[i].number, font);
    }
}

void display_nb_element(game_t *game, int i)
{
    if (game->inventory->element[i].nb > 0
                                    && game->inventory->element[i].class != 1)
        sfRenderWindow_drawText(game->window,
                                    game->inventory->element[i].number, NULL);
}

void display_element(game_t *game, int i)
{
    if (game->inventory->element[i].draw == 1)
        sfRenderWindow_drawSprite(game->window,
                            game->inventory->element[i].object->sprite, NULL);
}