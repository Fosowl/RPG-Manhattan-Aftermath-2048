/*
** EPITECH PROJECT, 2020
** src
** File description:
** main_scene loop
*/

#include "game_struct.h"
#include "inventory.h"
#include "scene.h"
#include "starset_engine.h"
#include "render.h"
#include "game_macro.h"
#include "warlock.h"

void play_music(char *path)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(path);
    sfSound *sound = sfSound_create();

    sfSound_setBuffer(sound, buffer);
    sfSound_setLoop(sound, true);
    sfSound_setVolume(sound, 65);
    sfSound_play(sound);
}

int main_scene_loop(game_t *game, sfClock *timer)
{
    game->window = game->screen->window;
    game->delay = 100;
    play_music("assets/audio/days_later.ogg");
    while (game->window) {
        if (!starset_running(game->window, &game->event))
            return EXIT_CLOSE;
        starset_entities_render_all(game->entities_runtime, game->window);
        starset_update_engine(game->entities_list, game->window, NULL);
        if (main_scene_update(game) == 1)
            break;
        sfRenderWindow_display(game->window);
        if (!manage_event(game))
            return EXIT_CLOSE;
        my_sleep(game->delay);
        sfRenderWindow_clear(game->window, BROWN);
        game->runtime = sfClock_getElapsedTime(timer);
    }
    return EXIT_SUCCESS;
}

int main_scene_update(game_t *game)
{
    if (update_value(game) == 1)
        return (1);
    move_dog(game->entities_list, game->player.save, game->girl->spot);
    update_object(game);
    //update_element(game);
    girl_ai(game);
    player_controller(game);
    player_switch_object(game->entities_list, game->player);
    handle_player_sound(game);
    zombie_ai(&game->entities_list, &game->player, &game->entities_runtime);
    if (game->player.ear_off != true) {
        handle_zombie_sound(game);
    }
    update_ui(game);

    return (0);
}