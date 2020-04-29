/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** player_attack
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "warlock.h"
#include "game_macro.h"
#include "path.h"

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
        closest->life -= 1;
        starset_entities_play_sound(closest, closest->name, "pain", false);
    }
}

static void attack_gun(game_t *game)
{
    entities_t *bullet = NULL;
    char *name = NULL;
    static int id = 0;

    name = append("bullet:", my_itoa(id));
    game->entities_list = starset_entities_add(game->entities_list
    , BULLET_PATH, name, false);
    game->bullet = starset_entities_get_propreties(game->entities_list
    , "bullet");
    bullet = starset_entities_get_propreties(game->bullet, name);
    starset_entities_get_propreties(bullet, "bullet")->is_trigger = true;
    starset_entities_get_propreties(bullet, "bullet")->speed = 9;
    bullet->spot.x = game->player.save->spot.x+
    90 * cos((game->player.angle / 57));
    bullet->spot.y = game->player.save->spot.y;
    bullet->angle = game->player.save->angle;
    if (compare(game->player.selected, "rifle")) {
        bullet->life = 40;
        game->player.ammo_rifle -= 1;
    } else {
        bullet->life = 25;
        game->player.ammo_gun -= 1;
    }
    id++;
}

static int on_attack(game_t *game, sfRenderWindow *window
, char *animation, int *r)
{
    if (limit_rate_gun(400) == 1)
        return (7);
    if (compare(game->player.selected, "rifle") && game->player.ammo_rifle < 0)
        return (7);
    if (compare(game->player.selected, "pistol") && game->player.ammo_gun <= 0)
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

static int switch_attack(game_t *game, int *r, sfRenderWindow *window)
{
    char *animation = NULL;

    if (*r == 2)
        return(on_attack(game, window, animation, r));
    if (*r == 3) {
        animation = append(game->player.selected, ":reload");
        if (compare(game->player.selected, "rifle"))
            game->player.ammo_rifle = 30;
        else
            game->player.ammo_gun = 11;
        *r = starset_play_animation(game->player.save, "player", animation, 1);
        if (!compare(game->player.selected, "knife"))
            game->player.noise = 1.3;
        if (*r == 1)
            *r = 3;
        return (7);
    }
    return (1);
}

int attack_entities(game_t *game, sfEvent *event
, sfRenderWindow *window)
{
    static int r = 0;
    int switch_r = 0;

    if (event->mouseButton.button == sfMouseLeft && !compare(game->player.selected
    , "torch")) {
        r = 2;
        event->mouseButton.button = -1;
    }
    if ((event->mouseButton.button == sfMouseRight ||
    event->key.code == game->player.control.key_reload) && !(compare
    (game->player.selected, "torch") || compare(game->player.selected
    , "knife"))) {
        starset_single_play_sound(game->player.save, "reload", false);
        r = 3;
        event->mouseButton.button = -1;
    }
    switch_r = switch_attack(game, &r, window);
    return (switch_r);
}