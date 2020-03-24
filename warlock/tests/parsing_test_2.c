/*
** EPITECH PROJECT, 2020
** warlock-C-libraries
** File description:
** parsing_test_2
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "warlock.h"

Test (copy_double, test_copy_double)
{
    char **array = clean_double_alloc(5, 5);
    char **copy = clean_double_alloc(5, 5);

    my_strcpy(array[0], "toto");
    my_strcpy(array[1], "tota");
    my_strcpy(array[2], "tido");
    my_strcpy(array[3], "toua");
    my_strcpy(array[4], "toro");
    copy_double(copy, array);
    cr_expect_str_eq(copy[0], "toto");
    cr_expect_str_eq(copy[1], "tota");
    cr_expect_str_eq(copy[2], "tido");
    cr_expect_str_eq(copy[3], "toua");
    cr_expect_str_eq(copy[4], "toro");
    free(array);
    free(copy);
}

Test (divide_array, test_divide_array)
{
    char *str = fill("hello i like french bread");
    char **result = NULL;

    result = divide_array(str, ' ');
    cr_expect_str_eq(result[0], "hello");
    cr_expect_str_eq(result[1], "i");
    cr_assert_str_eq(result[2], "like");
    cr_assert_str_eq(result[3], "french");
    cr_assert_str_eq(result[4], "bread");
}