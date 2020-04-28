/*
** EPITECH PROJECT, 2019
** rpg by martin, julie, leo, wilfried
** File description:
** main
*/

#include "dependancies.h"
#include "menu.h"

int main (int ac, char **argv)
{
    (void) ac;
    (void) argv;
    arg_t **arg = argument_parser(ac, argv);
    game_t game = {0};

    if (init_struct(&game) == 84)
        return (84);
    menu_loop(&game);
}
