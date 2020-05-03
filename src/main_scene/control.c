/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** control
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "warlock.h"
#include "game_macro.h"

static float point_toward_mouse(entities_t *entities, sfRenderWindow *window)
{
    float angle;
    sfVector2f mouse;
    sfVector2i mouse_i;

    mouse_i = sfMouse_getPositionRenderWindow(window);
    mouse.x = (float)mouse_i.x;
    mouse.y = (float)mouse_i.y;
    angle = starset_entities_rotate_to(entities, "player", mouse);
    return (angle);
}

void player_controller(game_t *game)
{
    int r = 0;
    char *animation = NULL;

    game->player.angle = point_toward_mouse(game->entities_list, game->window);
    if (press(sfKeyUp) || press(game->player.control.key_up))
        r = teleport_player_up(game->entities_list, game->player.save);
    if (press(sfKeyDown) || press(game->player.control.key_down))
        r = teleport_player_down(game->entities_list, game->player.save);
    if (press(sfKeyLeft) || press(game->player.control.key_left))
        r = teleport_player_left(game->entities_list, game->player.save);
    if (press(sfKeyRight) || press(game->player.control.key_right))
        r = teleport_player_right(game->entities_list, game->player.save);
    r = attack_entities(game, &game->event, game->window);
    if (r == 0)
        animation = append(game->player.selected, ":static");
    if (r == 1)
        animation = append(game->player.selected, ":move");
    if (r == 0 || r == 1)
        starset_play_animation(game->entities_list, "player", animation, 3);
    free(animation);
}