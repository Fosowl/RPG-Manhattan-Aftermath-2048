/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** game.c
*/

#include "dependancies.h"

int init_game(game_t *game)
{
    if (malloc_dialog(game) == FAILURE)
        return (FAILURE);
    game->back = malloc(sizeof(basic_object_t));
    if (game->back == NULL)
        return (FAILURE);
    game->dialog->next = 0;
    create_dialog(game->dialog);
    sfRenderWindow_setFramerateLimit(game->window, 30);
    return (0);
}

void background(game_t *game)
{
    game->back->texture = sfTexture_createFromFile("assets/back.jpg", NULL);
    game->back->sprite = sfSprite_create();

    sfSprite_setTexture(game->back->sprite, game->back->texture, 1);
    sfRenderWindow_drawSprite(game->window, game->back->sprite, NULL);
}

void game_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        background(game);
        display_dialog(game, 0, 0, 2);
        manage_event(game);
        sfRenderWindow_display(game->window);
    }
}

int starting_the_game(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};

    game->window = sfRenderWindow_create(mode, "My RPG", sfDefaultStyle, NULL);
    if (init_game(game) == FAILURE)
        return (FAILURE);
    game_loop(game);
    destroy_game(game);
    return (0);
}
