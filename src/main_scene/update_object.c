/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** update_object
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "render.h"
#include "game_macro.h"
#include "warlock.h"

static void game_over_ui(ui_t *ui, sfRenderWindow *window)
{
    static int v = 0;
    sfTime delay;
    sfClock *timer = NULL;

    if (!timer)
        timer = sfClock_create();
    ui->over_rect.top = v * ui->over_rect.height;
    sfSprite_setTextureRect(ui->over_sprite, ui->over_rect);
    sfSprite_setPosition(ui->over_sprite, ui->over_vector);
    sfRenderWindow_drawSprite(window, ui->over_sprite, NULL);
    delay = sfClock_getElapsedTime(timer);
    if (sfTime_asMilliseconds(delay) >= 150000) {
        sfClock_restart(timer);
        v++;
    }
    if (v > 8)
        v = 0;
}

int update_value(game_t *game)
{
    static int ok = 0;

    starset_reset_value(&game->player.noise, 5.0f, 1.0f);
    if (ok == 0) {
        game->bullet = starset_entities_get_propreties(game->entities_list
        , "bullet_1");
        if (game->bullet != NULL)
            ok = 1;
    }
    starset_play_animation(game->entities_runtime, "blood", "basic", 4);
    if (game->player.save->life <= 0) {
        game_over_ui(&game->ui, game->window);
        return (1);
    }
    return (0);
}

//game->entities_list = starset_entities_destroy(game->entities_list, tmp->name);

void update_object(game_t *game)
{
    entities_t *player_bullet = NULL;
    entities_t *girl_bullet = NULL;
    int d = 0;
    int d_2 = 0;

    player_bullet = starset_entities_get_propreties(game->entities_list
    , "bullet_1");
    girl_bullet = starset_entities_get_propreties(game->entities_list
    , "bullet_2");
    d = starset_get_distance(player_bullet->spot, game->player.save->spot);
    d_2 = starset_get_distance(girl_bullet->spot, game->girl->spot);
    if (d > 900) {
        player_bullet->life = 0;
        player_bullet->visible = 0;
        player_bullet->spot.y = -5000.0f;
    } else
        starset_move_from_angle(player_bullet, "bullet_1", player_bullet->angle, 20);
    if (d_2 > 900) {
        girl_bullet->spot.y = -5000.0f;
        girl_bullet->life = 0;
        girl_bullet->visible = 0;
    } else
        starset_move_from_angle(girl_bullet, "bullet_2", girl_bullet->angle, 20);
}