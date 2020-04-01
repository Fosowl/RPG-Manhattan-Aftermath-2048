/*
** EPITECH PROJECT, 2020
** include
** File description:
** game_struct
*/

#ifndef GAME_STRUCT_H_
#define GAME_STRUCT_H_

#include "dependancies.h"

typedef struct basicobject_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f vector;
    sfIntRect rect;
} basicobject_t;

typedef struct dialog_s {
    char ***text;
    basicobject_t *obj;
    sfText *script;
    sfText *person;
    sfText *next;
} dialog_t;

typedef struct game_s {
    dialog_t *dialog;
} game_t;

#endif /* !GAME_STRUCT_H_ */
