/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** destroy_dialog.c
*/

#include "dependancies.h"

void destroy_obj_dialog(dialog_t *dialog)
{
    sfTexture_destroy(dialog->obj->texture);
    sfSprite_destroy(dialog->obj->sprite);
}

void destroy_dialog(dialog_t *dialog)
{
    destroy_dialog(dialog);
}