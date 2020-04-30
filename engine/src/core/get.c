/*
** EPITECH PROJECT, 2020
** engine
** File description:
** get
*/

#include "../../include/internal.h"
#include "../../include/dependancies.h"

char **internal__get_class(char *name)
{
    char **all = clean_double_alloc_e(2, 10);

    if (!all)
        return NULL;
    if (search_e(":", name) == true) {
        all = divide_array_e(name, ':');
    } else {
        all[0] = name;
        all[1] = name;
    }
    if (!all)
        return NULL;
    return (all);
}

entities_t *starset_get_next(entities_t *entities, char *name)
{
    static entities_t *tmp = NULL;
    static entities_t *back = NULL;

    if (!tmp)
        tmp = entities;
    for ( ; tmp != NULL && search_e(name, tmp->name) == -1; tmp = tmp->next);
    back = tmp;
    if (!tmp)
        return (NULL);
    else
        tmp = tmp->next;
    if (!tmp)
        return (NULL);
    return (back);
}

entities_t *starset_get_closest(entities_t *entities, char *name)
{
    entities_t *closest = entities;
    entities_t *copy = entities;
    entities_t *from = starset_entities_get_propreties(entities, name);
    int distance = 21470000;

    (!from) ? put_err("bad name in get_closest()\n") : 0;
    if (from == NULL)
        return (NULL);
    while (copy != NULL) {
        if (from != copy && starset_get_distance
        (from->spot, copy->spot) < distance) {
            distance = starset_get_distance(from->spot, copy->spot);
            closest = copy;
        }
        copy = copy->next;
    }
    return (closest);
}