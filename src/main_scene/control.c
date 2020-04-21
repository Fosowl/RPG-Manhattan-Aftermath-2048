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

void player_controller(entities_t *entities, player_t *player
, sfEvent *event, sfRenderWindow *window)
{
    int r = 0;
    char *animation = NULL;

    player->save = starset_entities_get_propreties(entities, "player");
    player->angle = point_toward_mouse(entities, window);
    if (press(sfKeyUp) || press(player->control.key_up))
        r = teleport_player_up(entities, player->save);
    if (press(sfKeyDown) || press(player->control.key_down))
        r = teleport_player_down(entities, player->save);
    if (press(sfKeyLeft) || press(player->control.key_left))
        r = teleport_player_left(entities, player->save);
    if (press(sfKeyRight) || press(player->control.key_right))
        r = teleport_player_right(entities, player->save);
    r = attack_entities(player, event, window);
    if (r == 0)
        animation = append(player->selected, ":static");
    if (r == 1) {
        animation = append(player->selected, ":move");
    }
    if (r == 0 || r == 1)
        starset_play_animation(entities, "player", animation, 3);
    free(animation);
}