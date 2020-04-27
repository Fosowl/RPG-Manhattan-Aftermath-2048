/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** create_dialog.c
*/

#include "dialog.h"

basic_object_t *init_dialog(dialog_t *dialog)
{
    dialog->obj->texture = sfTexture_createFromFile("assets/dialog.png", NULL);
    dialog->obj->sprite = sfSprite_create();
    sfSprite_setTexture(dialog->obj->sprite, dialog->obj->texture, 1);
    return (dialog->obj);
}

void create_dialog(dialog_t *dialog)
{
    sfFont *font;
    sfVector2f vector_script = {230, 860};
    sfVector2f vector_person = {230, 770};

    dialog->script = sfText_create();
    font = sfFont_createFromFile("font/11.ttf");
    sfText_setFont(dialog->script, font);
    sfText_setPosition(dialog->script, vector_script);
    dialog->person = sfText_create();
    sfText_setFont(dialog->person, font);
    sfText_setPosition(dialog->person, vector_person);
    dialog->obj = init_dialog(dialog);
}