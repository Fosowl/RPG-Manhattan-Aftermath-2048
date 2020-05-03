/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** introduction
*/

#include "game_struct.h"
#include "inventory.h"
#include "scene.h"
#include "starset_engine.h"
#include "game_macro.h"
#include "path.h"

static void refresh_scene(sfSprite **sprite_load
, sfRenderWindow *window)
{
    int i = 0;
    sfBool lock = true;

    while (i < 3) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite_load[i], NULL);
        sfRenderWindow_display(window);
        if (!sfKeyboard_isKeyPressed(sfKeySpace))
            lock = false;
        if (lock == true)
            continue;
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            i++;
            lock = true;
        }
    }
}

void introduction_scene(game_t *game)
{
    sfTexture *texture_load[3];
    sfSprite *sprite_load[3];

    for (int i = 0; i < 3; i++)
        sprite_load[i] = sfSprite_create();
    texture_load[0] = sfTexture_createFromFile(INTRO_1_PATH, NULL);
    texture_load[1] = sfTexture_createFromFile(INTRO_2_PATH, NULL);
    texture_load[2] = sfTexture_createFromFile(INTRO_3_PATH, NULL);
    for (int i = 0; i < 3; i++)
        sfSprite_setTexture(sprite_load[i], texture_load[i], false);
    refresh_scene(&sprite_load, game->screen->window);
}
