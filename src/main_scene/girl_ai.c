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

static void girl_fire_gun(entities_t *closest, game_t *game
, sfBool attack_closest)
{
    entities_t *bullet;
    int d = 0;

    if (attack_closest == true) {
        if (limit_rate_girl(700) == 1)
            return;
        game->entities_list = starset_entities_add(game->entities_list
        , BULLET_PATH, "bullet:girl", false);
        game->bullet = starset_entities_get_propreties(game->entities_list
        , "bullet");
        bullet = starset_entities_get_propreties(game->entities_list, "bullet:girl");
        starset_entities_get_propreties(bullet, "bullet:girl")->is_trigger = true;
        starset_entities_get_propreties(bullet, "bullet:girl")->speed = 9;
        bullet->spot.x = game->girl->spot.x+
        90 * cos((game->girl->angle / 57));
        bullet->spot.y = game->girl->spot.y;
        bullet->angle = game->girl->angle;
        sleep (10);
    }
}

void girl_ai(game_t *game)
{
    entities_t *closest = starset_get_closest(game->entities_list, "sora");
    sfBool attack_closest = false;
    static sfBool follow_mode = false;

    starset_play_animation(game->girl, "sora", "pistol:move", 4);
    if (closest == NULL)
        return;
    if (search("zombie", closest->name) != -1) {
        starset_entities_rotate_to(game->girl, "sora", closest->spot);
        if (starset_get_distance(game->girl->spot
        , closest->spot) < 300)
            attack_closest = true;
    }
    if (follow_mode == true && starset_get_distance(game->girl->spot
    , game->player.save->spot)) {
        starset_entities_move(game->girl, "sora"
        , game->girl->spot.x, game->girl->spot.y);
    }
    girl_fire_gun(closest, game, attack_closest);
}