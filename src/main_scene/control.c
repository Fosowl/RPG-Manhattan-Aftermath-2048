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

static int teleport_player_up(entities_t *entities, entities_t *save)
{
    starset_entities_teleport(entities, "player"
    , save->position.x, save->position.y - 1);
    return (1);
}

static int teleport_player_down(entities_t *entities, entities_t *save)
{
    starset_entities_teleport(entities, "player"
    , save->position.x, save->position.y + 1);
    return (1);
}

static int teleport_player_left(entities_t *entities, entities_t *save)
{
    starset_entities_teleport(entities, "player"
    , save->position.x - 1, save->position.y);
    return (1);
}

static int teleport_player_right(entities_t *entities, entities_t *save)
{
    starset_entities_teleport(entities, "player"
    , save->position.x + 1, save->position.y);
    return (1);
}

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

void player_controller(entities_t *entities, player_t player
, sfEvent *event, sfRenderWindow *window)
{
    int r = 0;
    char *animation = NULL;

    player.angle = point_toward_mouse(entities, window);
    player.save = starset_entities_get_propreties(entities, "player");
    if (press(sfKeyUp) ||press(player.control.key_up))
        r += teleport_player_up(entities, player.save);
    if (press(sfKeyDown) || press(player.control.key_down))
        r += teleport_player_down(entities, player.save);
    if (press(sfKeyLeft) || press(player.control.key_left))
        r += teleport_player_left(entities, player.save);
    if (press(sfKeyRight) || press(player.control.key_right))
        r += teleport_player_right(entities, player.save);
    if (r == 0)
        animation = append(player.selected, ":static");
    else
        animation = append(player.selected, ":move");
    starset_play_animation(entities, "player", animation, 2);
}