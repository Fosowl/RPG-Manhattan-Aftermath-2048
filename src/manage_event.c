/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2019
** File description:
** manage_event.c
*/

#include "dependancies.h"

void manage_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed) {
            destroy_game(game);
            sfRenderWindow_close(game->window);
        }
        if (event.type == sfEvtKeyPressed
                                    && sfKeyboard_isKeyPressed(sfKeySpace) == 1)
            event_dialog(game->dialog);
    }
}
