/*
** EPITECH PROJECT, 2020
** output_test_2.c
** File description:
** output_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "warlock.h"

void redirect_basic(void)
{
    cr_redirect_stdout();
}

Test (my_printf, test_string, .init = redirect_basic)
{
    char *str = fill("hello");

    my_printf("%S world\n", str);
    cr_expect_stdout_eq_str("hello world\n");
    free(str);
}

Test (my_printf, print_number, .init = redirect_basic)
{
    int nb = 749;

    my_printf("nombre : %d %i\n", nb, 2);
    cr_expect_stdout_eq_str("nombre : 749 2\n");
}