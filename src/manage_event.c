/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2019
** File description:
** manage_event.c
*/

#include "dependancies.h"

void manage_event(sfRenderWindow *window, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        //if (event.type == )
        //    event_dialog(window, game);
    }
}
