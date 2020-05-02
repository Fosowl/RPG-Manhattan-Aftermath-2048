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

void check_pause(sfRenderWindow *window, sfEvent *event)
{
    sfBool on_pause = false;
    sfBool lock = true;

    while (sfRenderWindow_pollEvent(window, event)) {
        if (sfKeyboard_isKeyPressed(sfKeyP))
            on_pause = true;
    }
    while (on_pause == true) {
        if (!sfKeyboard_isKeyPressed(sfKeyP))
            lock = false;
        if (lock == true)
            continue;
        if (sfKeyboard_isKeyPressed(sfKeyP)) {
            on_pause = false;
        }
    }
}