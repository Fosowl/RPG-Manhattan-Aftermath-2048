/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** move_in_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"

void create_move(inventory_t *inventory)
{
    inventory->move->texture = sfTexture_createFromFile
                                        ("assets/inventory/select.png", NULL);
    inventory->move->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->move->sprite, inventory->move->texture, 1);
    inventory->move->vector.x = 460.5;
    inventory->move->vector.y = 900;
    sfSprite_setPosition(inventory->move->sprite, inventory->move->vector);
}

sfVector2f move_down(sfVector2f position, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (position.y + 100 >= 1000) {
            position.y = 515;
            game->inventory->location += 32;
        } else if (position.y + 100 == 900) {
            position.y += 100;
            game->inventory->location -= 8;
        } else {
            position.y += 95;
            game->inventory->location -= 8;
        }
    }
    return (position);
}

sfVector2f move_up(sfVector2f position, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (position.y - 100 <= 500) {
            position.y = 900;
            game->inventory->location -= 32;
        } else if (position.y - 100 == 800) {
            position.y -= 100;
            game->inventory->location += 8;
        } else {
            position.y -= 95;
            game->inventory->location += 8;
        }
    } else
        position = move_down(position, game);
    return (position);
}

sfVector2f move_x(sfVector2f position, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (position.x - 95 <= 365.5) {
            position.x = 1125;
            game->inventory->location += 7;
        } else {
            position.x -= 95;
            game->inventory->location -= 1;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        if (position.x + 95 >= 1220) {
            position.x = 460.5;
            game->inventory->location -= 7;
        } else {
            position.x += 95;
            game->inventory->location += 1;
        }
    }
    return (position);
}

void display_move(game_t *game)
{
    sfVector2f position = sfSprite_getPosition(game->inventory->move->sprite);
    static int stock = 0;

    position = move_x(position, game);
    position = move_up(position, game);
    sfSprite_setPosition(game->inventory->move->sprite, position);
    sfRenderWindow_drawSprite(game->window, game->inventory->move->sprite,
                                                                        NULL);

    if (game->inventory->element[game->inventory->location].status == 0) {
        if (game->inventory->element[stock].destroy_info == 1) {
            sfTexture_destroy(game->inventory->element[stock].info->texture);
            sfSprite_destroy(game->inventory->element[stock].info->sprite);
            game->inventory->element[stock].destroy_info = 0;
        }
    } else if (game->inventory->element[game->inventory->location].status != 0){
        stock = game->inventory->location;
        sfRenderWindow_drawSprite(game->window,
        game->inventory->element[game->inventory->location].info->sprite, NULL);
    }
}