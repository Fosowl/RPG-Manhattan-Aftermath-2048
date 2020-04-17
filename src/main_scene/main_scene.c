/*
** EPITECH PROJECT, 2020
** src
** File description:
** main_scene loop
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"

int main_scene(sfRenderWindow *window)
{
    sfEvent *event;
    entities_t *entities_list = NULL;

    while (starset_running(window, event)) {

    }
    starset_entities_destroy_all(entities_list);
    return EXIT_SUCCESS;
}
