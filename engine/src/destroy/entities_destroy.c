/*
** EPITECH PROJECT, 2020
** engine
** File description:
** free memory allocated for entities
*/

#include "../../include/internal.h"

static void internal__destroy_aspect(aspect_t *aspect)
{
    aspect_t *tmp = NULL;

    while (aspect != NULL) {
        tmp = aspect;
        aspect = aspect->next;
        if (tmp->sprite != NULL) {
            sfSprite_destroy(tmp->sprite);
            sfTexture_destroy(tmp->texture);
        }
        if (tmp->sheet == NULL)
            continue;
        free(tmp->sheet);
    }
}

static void internal__entities_destroy(entities_t *entities)
{
    internal__destroy_audio(entities->audio);
    internal__destroy_aspect(entities->aspect);
    internal__destroy_component(entities->component);
    free(entities);
}

void starset_entities_destroy_all(entities_t *entities)
{
    entities_t *tmp = NULL;

    while (entities != NULL) {
        tmp = entities;
        entities = entities->next;
        internal__entities_destroy(tmp);
    }
}

static entities_t *internal__reconnect_link(entities_t *copy, entities_t *tmp
, entities_t *entities, int *ok)
{
    if (copy->back != NULL) {
        copy->back->next = copy->next;
        if (copy->next != NULL)
            copy->next->back = copy->back;
    } else {
        entities = copy->next;
        entities->back = NULL;
    }
    copy = copy->next;
    internal__entities_destroy(tmp);
    *ok = true;
    return (entities);
}

entities_t *starset_entities_destroy(entities_t *entities, char *name)
{
    entities_t *tmp = NULL;
    entities_t *copy = entities;
    char **get = internal__get_class(name);
    sfBool ok = false;

    while (copy != NULL) {
        tmp = copy;
        if (search_e(get[0], copy->name) != -1 ||
        search_e(get[1], copy->name) != -1) {
            entities = internal__reconnect_link(copy, tmp, entities, &ok);
        } else
            copy = copy->next;
    }
    (!ok && !!LOG) ? put_err("bad name in entities_destroy()\n") : 0;
    return (entities);
}
