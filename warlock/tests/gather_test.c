/*
** EPITECH PROJECT, 2019
** test.c
** File description:
** files for testing programg using criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "warlock.h"

Test (count_digit, test_count_digit)
{
    float nb = 2312;

    cr_expect_eq(count_digit(&nb), 4);
    nb = 12;
    cr_expect_eq(count_digit(&nb), 2);
    nb = 130000;
    cr_expect_eq(count_digit(&nb), 6);
    nb = 2;
    cr_expect_eq(count_digit(&nb), 1);
    nb = 123;
    cr_expect_eq(count_digit(&nb), 3);
}

Test (char_in, test_char_in)
{
    cr_expect_eq(char_in('o', "toti"), 1);
    cr_expect_eq(char_in('b', "bonjour"), 0);
    cr_expect_eq(char_in('f', "touni"), -1);
}

Test (compare, test_compare)
{
    cr_expect_eq(compare("hello", "hello"), 1);
    cr_expect_eq(compare("hello", "bonjour"), 0);
    cr_expect_eq(compare("une phrase", "une phrdse"), 0);
}

Test (my_strlen, test_strlen)
{
    cr_expect_eq(my_strlen("hello"), 5);
}

Test (search, test_search)
{
    cr_expect_eq(search("sir", "hello sir how are you"), 6);
    cr_expect_eq(search("hello", "hello sir how are you"), 0);
    cr_expect_eq(search("siir", "hello sir how are you"), -1);
    cr_expect_eq(search("you", "hello sir how are you"), 18);
}
