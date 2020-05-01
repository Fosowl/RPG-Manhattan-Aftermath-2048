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
    srand(64886);
    game->delay = 1000;
    play_music("assets/audio/days_later.ogg");
    while (game->window) {
        if (!starset_running(game->window, &game->event))
            return EXIT_CLOSE;
        main_scene_update(game);
        starset_update_engine(game->entities_list, game->window, NULL);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, BROWN);
        check_pause(game);
        my_sleep(game->delay);
        game->runtime = sfClock_getElapsedTime(timer);
    }
    return EXIT_SUCCESS;
}

void main_scene_update(game_t *game)
{
    update_value(game);
    move_dog(game->entities_list, game->player.save);
    update_object(game);
    update_element(game);
    event_button_inventory(game);
    girl_ai(game);
    player_controller(game);
    player_switch_object(game->entities_list, game->player);
    handle_player_sound(game);
    zombie_ai(&game->entities_list, &game->player);
    if (game->player.ear_off != true) {
        handle_zombie_sound(game);
    }
    update_ui(game);
}