/*
** EPITECH PROJECT, 2020
** number_test.c
** File description:
** test number
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "warlock.h"

Test (nb_to_binary, test_nb_to_binary)
{
    cr_expect_str_eq(nb_to_binary(123), "1111011");
    cr_expect_str_eq(nb_to_binary(25), "11001");
    cr_expect_str_eq(nb_to_binary(2), "10");
}

Test (binary_to_nb, test_binary_to_nb)
{
    cr_expect_eq(binary_to_nb("1111011"), 123);
    cr_expect_eq(binary_to_nb("11001"), 25);
    cr_expect_eq(binary_to_nb("10"), 2);
}

Test (my_atoi, test_my_atoi)
{
    cr_expect_eq(my_atoi("11"), 11);
    cr_expect_eq(my_atoi("4"), 4);
    cr_expect_eq(my_atoi("95955959"), 95955959);
}

Test (my_itoa, test_my_itoa)
{
    cr_expect_str_eq(my_itoa(11), "11");
    cr_expect_str_eq(my_itoa(4), "4");
    cr_expect_str_eq(my_itoa(95955959), "95955959");
}

Test (my_sort_int_array, test_sorting)
{
    int *array = malloc(sizeof(int) * 5);

    array[0] = 9;
    array[1] = 1;
    array[2] = 4;
    array[3] = 3;
    array[4] = 8;
    my_sort_int_array(array, 5);
    my_putstr("\n--\n");
    my_putstr("\n");
    cr_expect_eq(array[0], 0);
    cr_expect_eq(array[1], 1);
    cr_expect_eq(array[2], 3);
    cr_expect_eq(array[3], 4);
    cr_expect_eq(array[4], 8);
    cr_expect_eq(array[5], 9);
}