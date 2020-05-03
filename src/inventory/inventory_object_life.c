/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** inventory_object_life.c
*/

#include "game_struct.h"
#include "inventory.h"

void option_value_care(game_t *game)
{
    switch (game->inventory->element[game->inventory->location].type)
    {
    case 10:
        if (game->player.save->life + 25 >= 100)
            game->player.save->life = 100;
        else
            game->player.save->life += 25;
        break;
    case 11:
        game->player.save->life = 100;
        break;
    }
}

void option_value_eat(game_t *game)
{
    switch (game->inventory->element[game->inventory->location].type)
    {
    case 8:
        if (game->player.save->life + 35 >= 100)
            game->player.save->life = 100;
        else
            game->player.save->life += 35;
        break;
    case 9:
        if (game->player.save->life + 15 >= 100)
            game->player.save->life = 100;
        else
            game->player.save->life += 15;
        break;
    default:
        option_value_care(game);
        break;
    }
}

void option_value_food(game_t *game)
{
    switch (game->inventory->element[game->inventory->location].type)
    {
    case 6:
        if (game->player.save->life + 60 >= 100)
            game->player.save->life = 100;
        else
            game->player.save->life += 60;
        break;
    case 7:
        if (game->player.save->life + 30 >= 100)
            game->player.save->life = 100;
        else
            game->player.save->life += 30;
        break;
    default:
        option_value_eat(game);
        break;
    }
}

void check_care(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyU)
        && game->inventory->element[game->inventory->location].status > 0
        && (game->inventory->element[game->inventory->location].class == 3
        || game->inventory->element[game->inventory->location].class == 4))
        option_value_food(game);
}