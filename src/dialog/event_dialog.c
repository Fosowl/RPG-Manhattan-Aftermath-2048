/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** event_dialog.c
*/

#include "dependancies.h"

void event_dialog(dialog_t *dialog)
{
    if (dialog->check[dialog->nb].draw == 1
        && dialog->nb_text >= dialog->nb / PERSONAGE) {
        dialog->next++;
        dialog->check[dialog->nb].draw = 2;
        if (dialog->check[(dialog->nb + dialog->next)].draw == 0
            && dialog->nb_text > dialog->nb / PERSONAGE) {
            dialog->check[(dialog->nb + dialog->next)].draw = 1;
        }
    }
}