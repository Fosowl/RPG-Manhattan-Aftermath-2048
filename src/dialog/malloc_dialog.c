/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** malloc_dialog.c
*/

#include "dialog.h"

int malloc_char_of_dialog(dialog_t *dialog, int i)
{
    for (int j = 0; j != TEXT; j++) {
        dialog->text[i][j] = malloc(sizeof(char) * (255 + 1));
        if (dialog->text[i][j] == NULL)
            return (84);
    }
    return (0);
}

int malloc_dialog_text(dialog_t *dialog)
{
    dialog->obj = malloc(sizeof(basic_object_t));
    dialog->text = malloc(sizeof(char *) * (PERSONAGE + 1));
    if (dialog->text == NULL)
        return (84);
    for (int i = 0; i != PERSONAGE; i++) {
        dialog->text[i] = malloc(sizeof(char *) * (TEXT + 1));
        if (dialog->text[i] == NULL)
            return (84);
        if (malloc_char_of_dialog(dialog, i) == 84)
            return (84);
    }
    return (0);
}

int malloc_dialog(game_t *game)
{
    game->dialog = malloc(sizeof(dialog_t));
    if (malloc_dialog(game->dialog) == 84)
        return (84);
    game->dialog->text[0][0] = "Salut Leo, pour rappel t'es vraiment nul a WZ";
    return (0);
}