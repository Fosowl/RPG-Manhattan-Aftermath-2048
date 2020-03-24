/*
** EPITECH PROJECT, 2020
** output_test.c
** File description:
** output_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "warlock.h"

Test (compare_letter, test_compare_letter)
{
    cr_expect_eq(compare_letter('a', 'A'), 1);
    cr_expect_eq(compare_letter('a', 'b'), 0);
}

Test (is_number, test_is_number)
{
    cr_expect_eq(is_number("124"), 1);
    cr_expect_eq(is_number("4f25"), 0);
}