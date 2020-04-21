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
    return (back);
}