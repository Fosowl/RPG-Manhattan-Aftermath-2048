/*
** EPITECH PROJECT, 2020
** engine
** File description:
** animator component
*/

#include "../../include/internal.h"

static void internal__play_animation_frame(aspect_t *aspect
, char *a_name, int *frame)
{
    animator_t *copy = aspect->sheet->a;
    animator_t *tmp = NULL;
    sfBool ok = false;

    while (copy != NULL) {
        if (compare_e(copy->name, a_name) == true) {
            aspect->sheet->current.x = copy->position[*frame].x;
            aspect->sheet->current.y = copy->position[*frame].y;
            ok = true;
        }
        tmp = copy;
        copy = copy->next;
    }
    (!ok && !!LOG) ? put_err("bad animation name in play_animation()\n") : 0;
    aspect->sheet->rect.left = aspect->sheet->current.x;
    aspect->sheet->rect.top = aspect->sheet->current.y;
    aspect->sheet->rect.width = tmp->size.x;
    aspect->sheet->rect.height = tmp->size.y;
    sfSprite_setTextureRect(aspect->sprite, aspect->sheet->rect);
    *frame += 1;
}

static void internal__update_animation_clock(entities_t *entitie, int fps)
{
    if (!entitie->aspect->sheet->a->delay)
        entitie->aspect->sheet->a->delay = sfClock_create();
    entitie->aspect->sheet->a->t = sfClock_getElapsedTime
    (entitie->aspect->sheet->a->delay);
    if (sfTime_asMilliseconds
    (entitie->aspect->sheet->a->t) < (1.0f / fps) * 1000.0f)
        return;
    sfClock_restart(entitie->aspect->sheet->a->delay);
}

void starset_play_animation(entities_t *entities, char *e_name
, char *a_name, int fps)
{
    sfBool ok = false;
    char **get = internal__get_class(e_name);
    static int frame = 0;

    for (entities_t *entitie = entities; entitie != NULL; entitie = entitie->next) {
        if (search_e(get[0], entitie->name) != -1 ||
        search_e(get[1], entitie->name) != -1) {
            internal__update_animation_clock(entitie, fps);
            (frame > entitie->aspect->sheet->a->max) ? frame = 0 : 0;
            internal__play_animation_frame(entitie->aspect, a_name, &frame);
        }
        ok = true;
    }
    (!ok && !!LOG) ? put_err("bad entities name in play_animation()\n") : 0;
}