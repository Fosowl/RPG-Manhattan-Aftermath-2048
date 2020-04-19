/*
** EPITECH PROJECT, 2020
** src
** File description:
** main_scene loop
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "render.h"
#include "game_macro.h"

int main_scene_load(game_t *game)
{
    sfClock *timer = sfClock_create();
    game->entities_list = load_entities_scene(4);

    if (!game->entities_list)
        return EXIT_FAILURE;
    if (main_scene_loop(game, timer) == EXIT_CLOSE) {
        starset_entities_destroy_all(game->entities_list);
        return EXIT_CLOSE;
    }
    starset_entities_destroy_all(game->entities_list);
    return EXIT_SUCCESS;
}

int main_scene_loop(game_t *game, sfClock *timer)
{
    game->window = game->screen->window;
    srand(64886);
    while (game->window) {
        if (!starset_running(game->window, &game->event))
            return EXIT_CLOSE;
        main_scene_update(game);
        starset_update_engine(game->entities_list, game->window, NULL);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, BROWN);
        my_sleep(10000);
        game->runtime = sfClock_getElapsedTime(timer);
    }
    return EXIT_SUCCESS;
}

void main_scene_update(game_t *game)
{
    starset_play_animation(game->entities_list, "player", "knife:static", 2);
    starset_play_animation(game->entities_list, "zombie", "static", 2);
}
