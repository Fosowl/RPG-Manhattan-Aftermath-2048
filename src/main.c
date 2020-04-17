/*
** EPITECH PROJECT, 2019
** rpg by martin, julie, leo, wilfried
** File description:
** main
*/

#include "dependancies.h"

int main (int ac, char **argv)
{
    (void) ac;
    (void) argv;
    arg_t **arg = argument_parser(ac, argv);
    game_t *game = malloc(sizeof(game_t));

    init_struct(game);
    menu_loop(game);
}
