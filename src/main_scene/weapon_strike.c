/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** weapon_strike
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "warlock.h"

static int limit_rate_gun(int wait)
{
    static sfClock *timer;
    sfTime delay;
    static int pass = 1;

    if (!timer)
        timer = sfClock_create();
    delay = sfClock_getElapsedTime(timer);
    if (sfTime_asMilliseconds(delay) < wait || pass == 1) {
        pass = 0;
        return (1);
    }
    sfClock_restart(timer);
    return (0);
}

static void attack_knife(game_t *game)
{
    player_t *player = &game->player;
    entities_t *closest = starset_get_closest(game->entities_list
    , player->save->name);

    if (closest && starset_get_distance(closest->spot
    , player->save->spot) < 90 && closest != player->save) {
        closest->life -= 40;
        if (search("zombie", closest->name) != -1) {
            blood_effect(&game->entities_runtime, closest);
        }
        starset_entities_play_sound(closest, closest->name, "pain", false);
    }
}

static void attack_gun(game_t *game)
{
    entities_t *bullet = NULL;
    static int id = 0;

    bullet = starset_entities_get_propreties(game->entities_list
    , "bullet_1");
    bullet->speed = 9;
    bullet->visible = true;
    bullet->spot.x = game->player.save->spot.x+
    90 * cos((game->player.angle / 57));
    bullet->spot.y = game->player.save->spot.y;
    bullet->angle = game->player.angle;
    if (compare(game->player.selected, "rifle")) {
        bullet->life = 45 + rand() % 20;
        game->player.ammo_rifle -= 1;
    } else {
        bullet->life = 30 + rand() % 10;
        game->player.ammo_gun -= 1;
    }
    id++;
}

static int weapon_empty(game_t *game)
{
    if (limit_rate_gun(1100) == 1 && !compare(game->player.selected, "knife"))
        return (7);
    if (limit_rate_gun(400) == 1 && compare(game->player.selected, "knife"))
        return (7);
    if (compare(game->player.selected, "rifle") &&
    game->player.ammo_rifle <= 0) {
        starset_single_play_sound(game->player.save, "empty", false);
        starset_play_animation(game->player.save, "player", "rifle:static", 2);
        return (7);
    } else if (compare(game->player.selected, "pistol") &&
    game->player.ammo_gun <= 0) {
        starset_single_play_sound(game->player.save, "empty", false);
        starset_play_animation(game->player.save, "player"
        , "pistol:static", 2);
        return (7);
    }
    return (0);
}

int on_attack(game_t *game, char *animation, int *r)
{
    if (weapon_empty(game) == 7)
        return (7);
    animation = append(game->player.selected, ":attack");
    *r = starset_play_animation(game->player.save, "player", animation, 3);
    starset_single_play_sound(game->player.save, game->player.selected, false);
    if (!compare(game->player.selected, "knife"))
        game->player.noise = 2.2;
    if (*r == 1)
        *r = 2;
    if (compare(game->player.selected, "knife"))
        attack_knife(game);
    else
        attack_gun(game);
    return (7);
}