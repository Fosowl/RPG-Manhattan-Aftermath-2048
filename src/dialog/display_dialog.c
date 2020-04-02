/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** dialog.c
*/

#include "dependancies.h"

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