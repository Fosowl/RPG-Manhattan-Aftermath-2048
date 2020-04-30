/*
** EPITECH PROJECT, 2020
** engine
** File description:
** core_update
*/

#include "../../include/internal.h"
#include "../../include/component.h"

static void full_debug(void *ptr)
{
    static int count = 0;
    static sfClock *timer;
    sfTime delay;
    thread_pass_t *pass = (thread_pass_t *)ptr;

    if (!timer)
        timer = sfClock_create();
    delay = sfClock_getElapsedTime(timer);
    printf("\n\n\n-----------DEBUG PASS %d------------\n", count);
    printf("image adress : %d\n", pass->image);
    printf("LOOP TIME %d millisecond\n", sfTime_asMilliseconds(delay) / (count + 10));
    for (entities_t *copy = pass->entities; copy; copy = copy->next) {
        printf("\nadress : %d or %p\n", copy, copy);
        printf("name : %s id : %d\n", copy->name, copy->id);
        printf("position %f %f\n", copy->spot.x, copy->spot.y);
        if (copy->collision)
            printf("collision with %s\n", copy->collision->name);
        else
            printf("no collision with any entities\n");
        printf("fixed : %d trigger : %d mouse hovering %d\n", copy->fixed
        , copy->is_trigger, copy->mouse_hover);
        printf("life : %d speed : %f mass : %f\n", copy->life, copy->speed, copy->mass);
    }
    count++;
}

void internal__dynamic_engine(void *ptr)
{
    thread_pass_t *pass = (thread_pass_t *)ptr;
    entities_t *player = NULL;

    for (entities_t *entitie = pass->entities; entitie != NULL
    ; entitie = entitie->next) {
        if (pass->image != NULL) {
            free (entitie->terrain);
            entitie->terrain = component__terrain_scanner(entitie
            , pass->image);
        }
        search_e("player", entitie->name) != -1 ? player = entitie : 0;
        internal__dynamic_sound(entitie, player);
        if (entitie)
            starset_entities_render_single(entitie, pass->window);
    }
}

void internal__collider_call(void *ptr)
{
    thread_pass_t *pass = (thread_pass_t *)ptr;

    internal__collider_update(pass->entities, pass->window);
}

static void internal__update_random(void)
{
    static sfClock *delay = NULL;
    sfTime t;

    (!delay) ? delay = sfClock_create() : 0;
    t = sfClock_getElapsedTime(delay);
    srand(sfTime_asMilliseconds(t));
}

int starset_update_engine(entities_t *entities, sfRenderWindow *window
, sfImage *image)
{
    thread_pass_t pass;

    internal__update_random();
    pass.entities = entities;
    pass.window = window;
    pass.image = image;
    internal__collider_call(&pass);
    internal__dynamic_engine(&pass);
    full_debug(&pass);
    return (0);
}