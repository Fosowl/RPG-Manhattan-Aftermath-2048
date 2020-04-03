/*
** EPITECH PROJECT, 2020
** include
** File description:
** game_struct
*/

#ifndef GAME_STRUCT_H_
#define GAME_STRUCT_H_

#include "dialog.h"

typedef struct game_s {
    dialog_t *dialog;
    basic_object_t *back;
} game_t;

#endif /* !GAME_STRUCT_H_ */
