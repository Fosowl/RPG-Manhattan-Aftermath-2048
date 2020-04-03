/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** game.c
*/

#include "dependancies.h"

int init_game(sfRenderWindow *window, game_t *game)
{
    if (malloc_dialog(game) == FAILURE)
        return (FAILURE);
    game->back = malloc(sizeof(basic_object_t));
    if (game->back == NULL)
        return (FAILURE);
    create_dialog(game->dialog);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (0);
}

void background(sfRenderWindow *window, game_t *game)
{
    game->back->texture = sfTexture_createFromFile("assets/back.jpg", NULL);
    game->back->sprite = sfSprite_create();
    sfSprite_setTexture(game->back->sprite, game->back->texture, 1);
    sfRenderWindow_drawSprite(window, game->back->sprite, NULL);
}

void game_loop(sfRenderWindow *window, game_t *game)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        background(window, game);
        display_dialog(window, game->dialog, 0, 0);
        display_dialog(window, game->dialog, 0, 1);
        display_dialog(window, game->dialog, 1, 0);
        display_dialog(window, game->dialog, 1, 1);
        display_dialog(window, game->dialog, 2, 0);
        display_dialog(window, game->dialog, 2, 1);
        display_dialog(window, game->dialog, 3, 0);
        display_dialog(window, game->dialog, 3, 1);
        manage_event(window, game);
        sfRenderWindow_display(window);
    }
}

void destroy_game(game_t *game, sfRenderWindow *window)
{

}

int starting_the_game(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    game_t game = {0};

    window = sfRenderWindow_create(mode, "My RPG", sfDefaultStyle, NULL);
    if (init_game(window, &game) == FAILURE)
        return (FAILURE);
    game_loop(window, &game);
    destroy_game(&game, window);
    return (0);
}
