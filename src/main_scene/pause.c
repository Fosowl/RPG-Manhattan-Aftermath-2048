/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** pause
*/

#include "game_struct.h"
#include "inventory.h"
#include "scene.h"
#include "starset_engine.h"
#include "render.h"
#include "game_macro.h"
#include "warlock.h"
#include "menu.h"

sfBool close_window_pause(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed) {
            return (false);
        }
    }
    return (true);
}

sfBool check_pause(game_t *game, sfEvent *event)
{
    sfBool on_pause = false;
    sfBool lock = true;

    if (sfKeyboard_isKeyPressed(sfKeyP)) {
        on_pause = true;
    }
    while (on_pause == true) {
        if (!sfKeyboard_isKeyPressed(sfKeyP))
            lock = false;
        if (lock == true)
            continue;
        if (pause_loop(game) == 1) {
            on_pause = false;
        }
        if (!close_window_pause(game->window, event))
            return (false);
    }
    return (true);
}

sfBool manage_event(game_t *game)
{
    if (!sfRenderWindow_isOpen(game->window))
        return (false);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed) {
            return (false);
        }
        if (!check_pause(game, &game->event))
            return (false);
        if (!pause_inventory(game))
            return (false);
    }
    return (true);
}
