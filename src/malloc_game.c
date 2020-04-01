/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** malloc_game.c
*/

#include "dependancies.h"

int malloc_game(game_t *game)
{
    game->dialog = malloc(sizeof(dialog_t));
    if (malloc_dialog(game->dialog) == 84)
        return (84);
    game->dialog->text[0][0] = "Salut Leo, pour rappel t'es vraiment nul a WARZONE";
    return (0);
}