/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** dialog.h
*/

#ifndef DIALOG_H_
#define DIALOG_H_

#define PERSONAGE (4)
#define TEXT (1)

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
    int nb_speech;
    int personage;
} dialog_t;

#include "game_struct.h"

//INIT
int malloc_dialog(game_t *);

//EVENT
void event_dialog(dialog_t *);

//REPLY
int read_file(dialog_t *);
char *recover_strings(char *, int, char *);
int loop_index(dialog_t *, char *, int);

//DIALOG
void create_dialog(dialog_t *);
void display_dialog(sfRenderWindow *, dialog_t *, int, int);

//DESTROY
void destroy_dialog(dialog_t *dialog);

#endif /* !DEPENDANCIES_H_ */