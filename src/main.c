/*
** EPITECH PROJECT, 2019
** kawai
** File description:
** main
*/

#include "dependancies.h"

// main function, use make tests_run to test
// the libraries after making change
// libraries .c file are found in warlock folder.

int main (int ac, char **argv)
{
    (void) ac;
    (void) argv;
    arg_t **arg = argument_parser(ac, argv);
    game_t *game = malloc(sizeof(game_t));

    init_struct(game);
    menu_loop(game);
    for (int i = 0; arg[i] != NULL; i++) {
        my_printf("argument : %s", arg[i]->option);
        for (int k = 0; arg[i]->content[k] != NULL; k++)
            my_printf(" value : %s", arg[i]->content[k]);
        my_putstr("\n");
    }
}
