/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** move_in_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"

basic_object_t *init_move(inventory_t *inventory)
{
    inventory->move->texture = sfTexture_createFromFile
                                        ("assets/inventory/select.png", NULL);
    inventory->move->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->move->sprite, inventory->move->texture, 1);
    inventory->move->vector.x = 460.5;
    inventory->move->vector.y = 900;
    sfSprite_setPosition(inventory->move->sprite, inventory->move->vector);
    return (inventory->move);
}

void create_move(inventory_t *inventory)
{
    inventory->move = init_move(inventory);
}

sfVector2f move_down(sfVector2f position)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (position.y + 100 >= 1000)
            position.y = 515;
        else if (position.y + 100 == 900)
            position.y += 100;
        else
            position.y += 95;
    }
    return (position);
}

sfVector2f move_up(sfVector2f position)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (position.y - 100 <= 500)
            position.y = 900;
        else if (position.y - 100 == 800)
            position.y -= 100;
        else
            position.y -= 95;
    }
    return (position);
}

void display_move(game_t *game)
{
    sfVector2f position = sfSprite_getPosition(game->inventory->move->sprite);

    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (position.x - 95 <= 365.5)
            position.x = 1125;
        else
            position.x -= 95;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (position.x + 95 >= 1220)
            position.x = 460.5;
        else
            position.x += 95;
    }
    position = move_down(position);
    position = move_up(position);
    sfSprite_setPosition(game->inventory->move->sprite, position);
    sfRenderWindow_drawSprite(game->window, game->inventory->move->sprite,
                                                                        NULL);
    sfRenderWindow_display(game->window);
}