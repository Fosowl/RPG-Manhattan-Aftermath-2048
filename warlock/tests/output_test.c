/*
** EPITECH PROJECT, 2020
** output_test.c
** File description:
** output_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "warlock.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
}

void redirect_all_out(void)
{
    cr_redirect_stdin();
}

char *random_fill(int nb)
{
    char *filled = clean_alloc(nb * sizeof(char));
    char randomLetter;

    for (int i = 0; i < nb; i++) {
        while (1) {
            randomLetter = rand() % 122;
            if (!((randomLetter >= 48 && randomLetter <= 57) ||
            randomLetter > 97))
                break;
        }
        if (rand() % 5 == 3)
            randomLetter = '%';
        filled[i] = randomLetter;
    }
    return (filled);
}

Test (my_printf, force_crash, .init=redirect_all_std)
{
    char *str = NULL;
    int i = 0;

    write(2, "\n\x1b[36mmy_printf brute force test start !\n", 42);
    while (i < 1000) {
        str = random_fill(10);
        my_putstr("testing with : ");
        my_putstr(str);
        my_putchar('\n');
        my_printf(str, "frere", "chien", "son", "frite", "montre");
        free(str);
        i++;
    }
    write(2, "\x1b[36mmy_printf brute force test [\x1b[30mOK\x1b[36m] !\n\n"
    , 51);
}