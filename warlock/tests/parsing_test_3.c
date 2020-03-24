/*
** EPITECH PROJECT, 2020
** warlock-C-libraries
** File description:
** parsing_test_3
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "warlock.h"

Test (pop, test_pop)
{
    char *str = fill("hello");

    cr_expect_str_eq(pop(str, 'h'), "ello");
}

Test (remove_char, test_remove_char)
{
    char *test = fill("la blanquette est bonne");

    remove_char(test, ' ', 0);
    cr_expect_str_eq(test, "lablanquetteestbonne");
    free(test);
}

Test (fusion, test_fusion)
{
    char *str_1 = fill("hello");
    char *str_2 = fill("world");

    str_1 = fusion(str_1, str_2, my_strlen(str_1));
    cr_expect_str_eq(str_1, "helloworld");
    free(str_1);
    free(str_2);
}

Test (replace, test_replace)
{
    char *str_1 = fill("hello guys");

    str_1 = replace(str_1, "guys", "dude");
    cr_expect_str_eq(str_1, "hello dude");
    free(str_1);
}

Test (my_strcpy, test_strcpy)
{
    char *str_1 = fill("hello guys");
    char *str_2 = clean_alloc(100);

    my_strcpy(str_2, str_1);
    cr_expect_str_eq(str_2, str_1);
    free(str_1);
    free(str_2);
}