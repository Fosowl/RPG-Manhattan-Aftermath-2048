/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** event_dialog.c
*/

#include "game_macro.h"
#include "dialog.h"

void event_dialog(game_t *game)
{
    if (press(sfKeySpace)) {
        if (game->dialog->check[game->dialog->nb].draw == 1
            && game->dialog->nb_text >= game->dialog->nb / MACRO_TALK) {
            game->dialog->next++;
            game->dialog->check[game->dialog->nb].draw = 2;
            if (game->dialog->check[(game->dialog->nb
                                                + game->dialog->next)].draw == 0
                && game->dialog->nb_text > game->dialog->nb / MACRO_TALK) {
                game->dialog->check[(game->dialog->nb
                                                + game->dialog->next)].draw = 1;
            }
        }
    }
}