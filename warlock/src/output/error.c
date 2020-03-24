/*
** EPITECH PROJECT, 2019
** error.c
** File description:
** error
*/

#include "warlock.h"

/*
\fn void put_error(char *str)
\brief put string on standard error output
\param str : the string to print.
\return nothing.
*/

void put_error(char *str)
{
    write(2, "\033[1;33m[ERROR] \033[1;39m", 22);
    write(2, str, my_strlen(str));
}

/*
\fn int error(long long int check, char *text)
\brief check error and put custom error message
\param text : the error message to be displayed.
\return 1 if error.
*/

int error(long long int check, char *text)
{
    if (check <= 0) {
        put_error(text);
        return (1);
    }
    return (0);
}

