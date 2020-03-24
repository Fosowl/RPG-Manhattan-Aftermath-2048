/*
** EPITECH PROJECT, 2020
** string_test.c
** File description:
** string
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "warlock.h"

Test (cut_tail, test_cut_tail)
{
    char *cutted = fill("hello world!");

    cutted = cut_tail(cutted, ' ');
    cr_expect_str_eq(cutted, "world!");
    free(cutted);
}

Test (empty_string, test_empty_string)
{
    char *str = fill("hello!");

    empty_string(str);
    cr_expect_str_eq(str, "");
    free(str);
}

Test (insert, test_insert)
{
    char *str = fill("hello!");
    char *t = clean_alloc(4);

    str = insert(str, 'b');
    cr_expect_str_eq(str, "bhello!");
    t = insert(t, 'b');
    cr_expect_str_eq(t, "b");
    free(str);
    free(t);
}

Test (capitalize, test_capitalize)
{
    char *str = fill("hello!");
    char *str_2 = fill("maRio");

    capitalize(str);
    cr_expect_str_eq(str, "HELLO!");
    capitalize(str_2);
    cr_expect_str_eq(str_2, "MARIO");
    free(str);
    free(str_2);
}

Test (append, test_append)
{
    char *str = fill("hello");

    cr_expect_str_eq(append(str, " world"), "hello world");
}
