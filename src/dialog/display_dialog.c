/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** dialog.c
*/

#include "dialog.h"

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

void display_dialog(game_t *game, int personage, int text, int nb_text)
{
    char *name = choice_person(personage);
    static int a = 0;

    game->dialog->nb = (personage * TEXT) + game->dialog->next;
    if (game->dialog->next == 0 && a == 0)
        game->dialog->check[game->dialog->nb].draw = 1;
    if (game->dialog->check[game->dialog->nb].draw == 1) {
        game->dialog->nb_text = (personage * TEXT) + nb_text;
        sfRenderWindow_drawSprite(game->window, game->dialog->obj->sprite,
                                                                        NULL);
        sfText_setString(game->dialog->script,
                    game->dialog->text[personage][text + game->dialog->next]);
        sfText_setString(game->dialog->person, name);
        sfRenderWindow_drawText(game->window, game->dialog->script, NULL);
        sfRenderWindow_drawText(game->window, game->dialog->person, NULL);
    }
    a++;
}