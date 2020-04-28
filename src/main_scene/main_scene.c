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

static void load_value(game_t *game)
{
    game->player.angle = 0.0f;
    game->player.control.key_up = sfKeyZ;
    game->player.control.key_down = sfKeyS;
    game->player.control.key_left = sfKeyQ;
    game->player.control.key_right = sfKeyD;
    game->player.control.key_reload = sfKeyR;
    game->player.control.key_inventory = sfKeyI;
    game->player.control.key_map = sfKeyM;
    game->player.control.key_weapon[0] = sfKeyNum1;
    game->player.control.key_weapon[1] = sfKeyNum2;
    game->player.control.key_weapon[2] = sfKeyNum3;
    game->player.control.key_weapon[3] = sfKeyNum4;
    game->player.selected = fill("pistol");
    game->player.ear_off = false;
    game->player.nb_magazine_gun = 5;
    game->player.nb_magazine_rifle = 3;
    game->player.ammo_gun = 11;
    game->player.ammo_rifle = 30;
}

int main_scene_load(game_t *game)
{
    sfClock *timer = sfClock_create();
    game->entities_list = load_entities_scene(10, game->screen->window);

    if (!game->entities_list)
        return EXIT_FAILURE;
    load_value(game);
    if (main_scene_loop(game, timer) == EXIT_CLOSE) {
        starset_entities_destroy_all(game->entities_list);
        return EXIT_CLOSE;
    }
    starset_entities_destroy_all(game->entities_list);
    return EXIT_SUCCESS;
}

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
    play_music("assets/audio/days_later.ogg");
    create_case_element(game->inventory);
    while (game->window) {
        if (!starset_running(game->window, &game->event))
            return EXIT_CLOSE;
        main_scene_update(game);
        starset_update_engine(game->entities_list, game->window, NULL);
        display_case_element(game);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, BROWN);
        my_sleep(10000);
        game->runtime = sfClock_getElapsedTime(timer);
    }
    return EXIT_SUCCESS;
}

void main_scene_update(game_t *game)
{
    reset_value(game);
    move_dog(game->entities_list, game->player.save);
    update_object(game);
    event_button_inventory(game);
    player_controller(game);
    player_switch_object(game->entities_list, game->player, &game->event);
    handle_player_sound(game);
    zombie_ai(&game->entities_list, &game->player);
    if (game->player.ear_off != true) {
        handle_zombie_sound(game);
    }
    update_ui(game);
}