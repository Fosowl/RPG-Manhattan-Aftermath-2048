/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** dialog.c
*/

#include "dependancies.h"

basicobject_t *init_dialog(dialog_t *dialog)
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
    font = sfFont_createFromFile("font/8.ttf");
    sfText_setFont(dialog->script, font);
    sfText_setPosition(dialog->script, vector_script);
    dialog->person = sfText_create();
    sfText_setFont(dialog->person, font);
    sfText_setPosition(dialog->person, vector_person);
    dialog->obj = init_dialog(dialog);
}

char *choice_person(int personage)
{
    char *name = NULL;

    switch (personage)
    {
        case 0:
            name = "JULIE";
            break;
        case 1:
            name = "LEO";
            break;
        case 2:
            name = "MARTIN";
            break;
        case 3:
            name = "WILFRIED";
            break;
    }
    return (name);
}

void display_dialog(sfRenderWindow *window, dialog_t *dialog,
                                                    int personage, int text)
{
    char *name = choice_person(personage);

    sfRenderWindow_drawSprite(window, dialog->obj->sprite, NULL);
    sfText_setString(dialog->script, dialog->text[personage][text]);
    sfText_setString(dialog->person, name);
    sfRenderWindow_drawText(window, dialog->script, NULL);
    sfRenderWindow_drawText(window, dialog->person, NULL);
}