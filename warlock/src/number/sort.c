/*
** EPITECH PROJECT, 2019
** sort
** File description:
** sort a int array
*/

#include "warlock.h"

/*
\fn void my_sort_int_array(int *array, int size)
\brief sort an array of int in order.
\param array : the array of int.
\param size : the size of the array of int.
\return nothing.
*/

void my_sort_int_array(int *array, int size)
{
    int temp = 0;
    int *copy = malloc(sizeof(int) * size);

    if (DEBUG_MODE == 1)
        debug_log("my_sort_int_array()", array);
    for (int i = 0; i < size; i++) {
        copy[i] = array[i];
        if (array[i] > array[i + 1]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }
    for (int b = 0; b < size; b++) {
        if (!(array[b] <= array[b + 1]))
            my_sort_int_array(array, size);
    }
}