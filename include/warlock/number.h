/*
** EPITECH PROJECT, 2020
** number.h
** File description:
** number function include for warlock lib
*/

#ifndef NUMBER_H_
#define NUMBER_H_

#include "warlock.h"

// ............  base.c

/*
\fn char *nb_to_binary(int nb)
\brief convert a decimal number to binary.
\param nb : the number to convert.
\return a string that represent the number in binary.
*/

char *nb_to_binary(int nb);

/*
\fn int binary_to_nb(char *str)
\brief convert binary to number.
\param str : the binary number to convert.
\return decimal number.
*/

int binary_to_nb(char *str);

/*
\fn int octal_to_decimal(int decimal)
\brief convert binary to number.
\param str : the binary number to convert.
\return decimal number.
*/

int octal_to_decimal(int decimal);

//............  convertion.c

/*
\fn long long my_atoi(char *str)
\brief convert string to number.
\param str : the string (in char *) that represent the number.
\return a long long that represent the number in long long format.
*/

char *my_itoa(int nb);

/*
\fn char *my_itoa(int nb)
\brief convert number to string.
\param nb : a int that contain the number you want to convert.
\return a string that represent the number.
*/

long long my_atoi(char *str);

// ..............converter.c

/*
\fn char *format_from_human_base(char *calculated, char *base)
\brief convert a number from any base to any base.
\param calculated : the number to convert in string format.
\param base : the base you convert to.
\return a string that result of the convertion.
*/

char *format_from_human_base(char *calculated, char *base);

// ............  sort.c

/*
\fn void my_sort_int_array(int *array, int size)
\brief sort an array of int in order.
\param array : the array of int.
\param size : the size of the array of int.
\return nothing.
*/

void my_sort_int_array(int *array, int size);

#endif /* !NUMBER_H_ */
