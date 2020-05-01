/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** player_attack
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "game_macro.h"
#include "warlock.h"

static int limit_rate_reload(int wait)
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

static int switch_attack(game_t *game, int *r, sfRenderWindow *window)
{
    char *animation = NULL;

    if (*r == ATTACK)
        return(on_attack(game, window, animation, r));
    if (*r == RELOAD) {
        animation = append(game->player.selected, ":reload");
        if (compare(game->player.selected, "rifle"))
            game->player.ammo_rifle = 30;
        else
            game->player.ammo_gun = 11;
        *r = starset_play_animation(game->player.save, "player", animation, 1);
        game->player.noise = 1.3;
        if (*r == 1 || limit_rate_reload(2100) == 1)
            *r = RELOAD;
        else
            *r = 0;
        return (7);
    }
    return (1);
}

int attack_entities(game_t *game, sfEvent *event
, sfRenderWindow *window)
{
    static int r = 0;
    int switch_r = 0;

    if (event->mouseButton.button == sfMouseLeft && !compare
    (game->player.selected, "torch") && r != RELOAD) {
        r = ATTACK;
        event->mouseButton.button = -1;
    }
    if ((event->mouseButton.button == sfMouseRight ||
    event->key.code == game->player.control.key_reload) && !(compare
    (game->player.selected, "torch") || compare(game->player.selected
    , "knife"))) {
        starset_single_play_sound(game->player.save, "reload", false);
        r = RELOAD;
        event->mouseButton.button = -1;
    }
    switch_r = switch_attack(game, &r, window);
    return (switch_r);
}