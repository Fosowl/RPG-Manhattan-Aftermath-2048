/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** game.c
*/

#include "dependancies.h"

int init_game(sfRenderWindow *window, game_t *game)
{
    if (malloc_dialog(game) == 84)
        return (84);
    create_dialog(game->dialog);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (0);
}

void game_loop(sfRenderWindow *window, game_t *game)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_dialog(window, game->dialog, 0, 0);
        manage_event(window, game);
        sfRenderWindow_display(window);
    }
}

/*void destroy_game(game_t *game, sfRenderWindow *window)
{

}*/

int starting_the_game(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    game_t game = {0};

    window = sfRenderWindow_create(mode, "My RPG", sfDefaultStyle, NULL);
    if (init_game(window, &game) == 84)
        return (84);
    game_loop(window, &game);
    //destroy_game(&game, window);
    return (0);
}
