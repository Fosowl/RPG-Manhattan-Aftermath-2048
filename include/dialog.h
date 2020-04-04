/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** dialog.h
*/

#ifndef DIALOG_H_
#define DIALOG_H_

#define PERSONAGE (4)
#define TEXT (2)

#include <stdbool.h>

typedef struct basic_object_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f vector;
    sfIntRect rect;
} basic_object_t;

typedef struct check_text_s{
    int draw;
} check_text_t;

typedef struct dialog_s {
    char ***text;
    basic_object_t *obj;
    check_text_t *check;
    sfText *script;
    sfText *person;
    int next;
    int nb_text;
    int nb;
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
void display_dialog(game_t *, int, int, int);

//DESTROY
void destroy_dialog(dialog_t *);

#endif /* !DEPENDANCIES_H_ */