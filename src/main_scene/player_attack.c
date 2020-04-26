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

static void attack_knife(game_t *game)
{
    player_t *player = &game->player;
    entities_t *closest = starset_get_closest(game->entities_list
    , player->save->name);

    if (closest && starset_get_distance(closest->position
    , player->save->position) < 150) {
        closest->life -= 50;
    }
}

static void attack_gun(game_t *game)
{
    entities_t *bullet = NULL;

    bullet = starset_entities_get_propreties(game->player.save, "bullet");
    if (bullet->visible == false) {
        bullet->position.x = game->player.save->position.x+
        90 * cos((game->player.angle / 57));
        bullet->position.y = game->player.save->position.y;
        bullet->angle = game->player.angle;
        bullet->visible = true;
    }
}

static int on_attack(game_t *game, sfRenderWindow *window
, char *animation, int *r)
{
    animation = append(game->player.selected, ":attack");
    *r = starset_play_animation(game->player.save, "player", animation, 3);
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

    if (*r == 2) {
        return(on_attack(game, window, animation, r));
    }
    if (*r == 3) {
        animation = append(game->player.selected, ":reload");
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
        starset_single_play_sound(game->player.save, game->player.selected, false);
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