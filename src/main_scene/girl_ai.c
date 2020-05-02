/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** girl_ai
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "path.h"
#include "game_macro.h"
#include "warlock.h"

static int limit_rate_girl(int wait)
{
    static sfClock *timer;
    sfTime delay;

    if (!timer)
        timer = sfClock_create();
    delay = sfClock_getElapsedTime(timer);
    if (sfTime_asMilliseconds(delay) < wait)
        return (1);
    sfClock_restart(timer);
    return (0);
}

static void girl_fire_gun(game_t *game
, sfBool attack_closest)
{
    entities_t *bullet;

    if (attack_closest == true) {
        if (limit_rate_girl(1300) == 1)
            return;
        starset_entities_play_sound(game->girl, "sora", "pistol", false);
        bullet = starset_entities_get_propreties(game->entities_list
        , "bullet_2");
        bullet->speed = 9;
        bullet->visible = true;
        bullet->spot.x = game->girl->spot.x+
        90 * cos((game->girl->angle / 57));
        bullet->spot.y = game->girl->spot.y;
        bullet->angle = game->girl->angle;
    }
}

void girl_ai(game_t *game)
{
    entities_t *closest = starset_get_closest(game->entities_list, "sora");
    sfBool attack_closest = false;
    static sfBool follow_mode = false;

    if (!closest)
        return;
    starset_play_animation(game->girl, "sora", "pistol:move", 4);
    if (search("zombie", closest->name) != -1) {
        starset_entities_rotate_to(game->girl, "sora", closest->spot);
        if (starset_get_distance(game->girl->spot, closest->spot) < 300)
            attack_closest = true;
    }
    if (starset_get_distance(game->girl->spot
    , game->player.save->spot) < 190)
        follow_mode = true;
    if (follow_mode == true && starset_get_distance(game->girl->spot
    , game->player.save->spot) > 90)
        starset_entities_move(game->girl, "sora"
        , game->player.save->spot.x, game->player.save->spot.y);
    girl_fire_gun(game, attack_closest);
}