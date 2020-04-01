/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** dialog.h
*/

#ifndef DIALOG_H_
#define DIALOG_H_

#define PERSONAGE (1)
#define TEXT (1)
#include "dependancies.h"

typedef struct basic_object_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f vector;
    sfIntRect rect;
} basic_object_t;

typedef struct dialog_s {
    char ***text;
    basic_object_t *obj;
    sfText *script;
    sfText *person;
    sfText *next;
} dialog_t;

//INIT
int malloc_dialog(dialog_t *);

//EVENT

//DIALOG
void create_dialog(dialog_t *);
void display_dialog(sfRenderWindow *, dialog_t *, int personage, int text);


#endif /* !DEPENDANCIES_H_ */