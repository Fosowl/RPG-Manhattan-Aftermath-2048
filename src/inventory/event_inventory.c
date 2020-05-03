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

int event_move(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        display_move(game);
        check_care(game);
        sfRenderWindow_display(game->window);
        if (game->event.type == sfEvtClosed) {
            return (0);
        }
    }
    return (1);
}

sfBool pause_inventory(game_t *game)
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
        if ((!event_move(game)))
            return (false);
        if (sfKeyboard_isKeyPressed(sfKeyI))
            on_pause = false;
    }
    game->inventory->button = 0;
    return (true);
}