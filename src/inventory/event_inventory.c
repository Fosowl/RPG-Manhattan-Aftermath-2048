/*
** EPITECH PROJECT, 2019
** rpg_en_cours
** File description:
** event_inventory.c
*/

#include "game_struct.h"
#include "inventory.h"
#include "scene.h"
#include "starset_engine.h"
#include "render.h"
#include "game_macro.h"
#include "warlock.h"

int event_button_inventory(game_t *game)
{
    if (press(sfKeyI)) {
        if (game->inventory->button == 1)
            game->inventory->button = 0;
        else
            game->inventory->button = 1;
    }
    return (game->inventory->button);
}

sfBool pause_inventory(sfRenderWindow *window, sfEvent *event, game_t *game)
{
    static sfBool on_pause = false;
    sfBool lock = true;

    if (sfKeyboard_isKeyPressed(sfKeyI) && on_pause == false) {
        on_pause = true;
        game->inventory->button = 1;
    }
    while (on_pause == true) {
        update_element(game);
        if (!sfKeyboard_isKeyPressed(sfKeyI))
            lock = false;
        if (lock == true)
            continue;
        if (sfKeyboard_isKeyPressed(sfKeyI)) {
            on_pause = false;
        }
        if (!close_window_pause(window, event))
            return (false);
        sfRenderWindow_display(game->window);
    }
    game->inventory->button = 0;
    return (true);
}