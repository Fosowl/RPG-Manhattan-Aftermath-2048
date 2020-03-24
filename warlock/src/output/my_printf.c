/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** c printing function remake
*/

#include "warlock.h"

// sub-function of my_printf

int put_ptr(void *a)
{
    long long int adress = (long long int)a;

    my_putstr("0x");
    my_putstr(format_from_human_base(my_itoa(adress), "0123456789ABCDEF"));
    return (0);
}

// sub-function of my_printf

int put_octal(void *number)
{
    int nb = (long long int)number;

    nb = octal_to_decimal(nb);
    my_putstr(my_itoa(nb));
    return (0);
}

// sub-function of my_printf

static void load_function_adress(int (*call[])(void *))
{
    call[0] = call_my_putchar;
    call[1] = call_my_put_nbr;
    call[2] = call_my_put_nbr;
    call[3] = NULL;
    call[4] = NULL;
    call[5] = NULL;
    call[6] = call_put_binary;
    call[7] = handle_case;
    call[8] = put_octal;
    call[9] = call_my_putstr;
    call[10] = call_my_put_nbr;
    call[11] = put_hexa;
    call[12] = put_capital_hexa;
    call[13] = put_ptr;
    call[14] = NULL;
    call[15] = call_my_putchar;
}

// sub-function of my_printf

static void cast_and_call(int r, va_list list)
{
    int (*call[16])(void *);

    load_function_adress(call);
    if (r == 0 || r == 15)
        (*call[r])(va_arg(list, int *));
    if (r == 1 || r == 2 || r == 8 || r == 6 || (r >= 10 && r <= 12))
        (*call[r])(va_arg(list, int *));
    if (r == 7 || r == 9)
        (*call[r])(va_arg(list, char *));
    if (r == 13)
        (*call[r])(va_arg(list, void *));
}

/*
\fn int my_printf(char *str, ...)
\brief same usage as real printf function
see "man printf" to learn usage.
\param str : the string to print with the flags.
\param ... : dynamic number of flags.
\return 0.
*/

int my_printf(char *str, ...)
{
    va_list list;
    int r = 0;
    char *select = fill("cdieEfbSosuxXpn%");

    va_start(list, str);
    for (int i = 0; str[i] != '\0'; i++) {
        r = char_in(str[i + 1], select);
        if (str[i] == '%' && r != -1) {
            cast_and_call(r, list);
            i++;
        } else
            my_putchar(str[i]);
    }
    va_end(list);
    return (0);
}