/*
** EPITECH PROJECT, 2020
** output.h
** File description:
** output function include for warlock lib
*/

#ifndef OUTPUT_H_
#define OUTPUT_H_

// converter.c

/*
\fn void put_binary(int nb)
\brief print number in binary.
\param nb : the number to print in binary.
\return nothing.
*/

void put_binary(int nb);

/*
\fn void put_hexa(int nb)
\brief print number in hexadecimal
\param nb : the number to print in hexadecimal.
\return nothing.
*/

void put_hexa(void *number);

/*
\fn int put_capital_hexa(void *number)
\brief print number in hexadecimal
\param number : the number to print in hexadecimal in maj.
\return 0.
*/

int put_capital_hexa(void *number);

// error.c

/*
\fn void put_error(char *str)
\brief put string on standard error output
\param str : the string to print.
\return nothing.
*/

void put_error(char *str);

/*
\fn int error(long long int check, char *text)
\brief check error and put custom error message
\param text : the error message to be displayed.
\return 1 if error.
*/

int error(long long int check, char *text);

// my_printf.c

int put_ptr(void *a);
int put_octal(void *number);

/*
\fn int my_printf(char *str, ...)
\brief same usage as real printf function
see "man printf" to learn usage.
\param str : the string to print with the flags.
\param ... : dynamic number of flags.
\return 0.
*/

int my_printf(char *str, ...);

// call_function.c

int call_my_putchar(void *c);
int call_my_put_nbr(void *number);
int call_put_binary(void *number);
int call_my_putstr(void *string);

// my_putnbr.c

/*
\fn void put_hexa(int nb)
\brief print number in hexadecimal
\param nb : the number to print in hexadecimal.
\return nothing.
*/

void put_hexa(void *number);

/*
\fn int my_put_nbr(int nb)
\brief print number on standard output
\param nb : the number to print.
\return 0.
*/

int my_put_nbr(int nb);

// my_putchar.c

/*
\fn void my_putchar(char c)
\brief function to put one character on the
standard output
\param c : the character to print on standart output.
\return 0.
*/

void my_putchar(char c);

// my_putstr.c

/*
\fn void my_putstr(char *str)
\brief print a string to stantard output.
\param str : the string to print.
\return 0.
*/

void my_putstr(char *str);

// print_float.c

/*
\fn int my_print_float(float percent)
\brief print a float number.
\param percent : (float) the float number to print
on standard output.
\return 0.
*/

int my_print_float(float percent);

#endif /* !OUTPUT_H_ */
