/*
** EPITECH PROJECT, 2020
** include
** File description:
** game_struct
*/

#ifndef GAME_STRUCT_H_
#define GAME_STRUCT_H_

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

typedef struct game_s {
    dialog_t *dialog;
    sfRenderWindow *window;
} game_t;

#endif /* !GAME_STRUCT_H_ */
