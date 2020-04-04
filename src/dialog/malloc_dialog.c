/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** malloc_dialog.c
*/

#include "dependancies.h"

int malloc_char_of_dialog(dialog_t *dialog, int i)
{
    for (int j = 0; j != TEXT; j++) {
        dialog->text[i][j] = malloc(sizeof(char) * (255 + 1));
        if (dialog->text[i][j] == NULL)
            return (FAILURE);
    }
    return (0);
}

int malloc_dialog_text(dialog_t *dialog)
{
    dialog->obj = malloc(sizeof(basic_object_t));
    dialog->text = malloc(sizeof(char *) * (PERSONAGE + 1));
    if (dialog->text == NULL)
        return (FAILURE);
    for (int i = 0; i != PERSONAGE; i++) {
        dialog->text[i] = malloc(sizeof(char *) * (TEXT + 1));
        if (dialog->text[i] == NULL)
            return (FAILURE);
        if (malloc_char_of_dialog(dialog, i) == FAILURE)
            return (FAILURE);
    }
    return (0);
}

int malloc_dialog(game_t *game)
{
    game->dialog = malloc(sizeof(dialog_t));
    game->dialog->check = malloc(sizeof(check_text_t) * (PERSONAGE * TEXT));
    for (int i = 0; i != (PERSONAGE * TEXT); i++)
        game->dialog->check[i].draw = 0;
    if (malloc_dialog_text(game->dialog) == FAILURE)
        return (FAILURE);
    if (read_file(game->dialog) == FAILURE)
        return (FAILURE);
    return (0);
}