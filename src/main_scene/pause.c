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

void check_pause(void)
{
    sfBool on_pause = false;
    sfBool protect = false;
    sfClock *timer = NULL;
    sfTime delay;

    if (!timer)
        timer = sfClock_create();
    delay = sfClock_getElapsedTime(timer);
    if (sfTime_asMilliseconds(delay) >= 100000)
        protect = false;
    if (sfKeyboard_isKeyPressed(sfKeyP) && on_pause == false &&
    protect == false)
        on_pause = true;
    while (on_pause && protect == false) {
        my_sleep(100000);
        if (sfKeyboard_isKeyPressed(sfKeyP) && on_pause == true) {
            on_pause = false;
            protect = true;
            sfClock_restart(timer);
        }
    }
}