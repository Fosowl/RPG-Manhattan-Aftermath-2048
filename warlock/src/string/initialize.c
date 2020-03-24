/*
** EPITECH PROJECT, 2019
** initialize.c
** File description:
** usefull function
*/

#include "warlock.h"

/*
\fn char *clean_alloc(int size)
\brief allocate string and fill it with '\0'
\param size : the number of char the string can contain.
\return the allocated string.
*/

char *clean_alloc(int size)
{
    char *str = NULL;

    str = malloc(size * sizeof(char));
    if (str == NULL) {
        my_putstr("allocation error !");
        return (NULL);
    }
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}

/*
\fn char *fill(char *with)
\brief allocate string and fill string with another
\param with : the string to fill with.
\return this : new string filled and allocated.
*/

char *fill(char *with)
{
    int i = 0;
    char *this = NULL;

    this = clean_alloc(sizeof(char) * my_strlen(with) + 2);
    if (this == NULL)
        return (NULL);
    for (i = 0; with[i] != '\0'; i++) {
        this[i] = with[i];
    }
    this[i] = '\0';
    return (this);
}

/*
\fn void fill_double(char **dest, char **temp, int nb)
\brief allocate and copy an array of string into another.
\param dest : the 2d array to fill with.
\return (char **) the allocated and filled array of string.
*/

char **fill_double(char **temp)
{
    int	i = 0;
    int o = 0;
    int nb = array_lenght(temp);
    char **dest = clean_double_alloc(nb + 1, my_strlen(temp[0]) + 1);

    DEBUG_MODE == 1 ? debug_log("fill_double() arg", temp) : 0;
    while (o < nb) {
        while (temp[o][i] != '\0')
        {
            dest[o][i] = temp[o][i];
            i = i + 1;
        }
        dest[o][i] = '\0';
        i = 0;
        o += 1;
    }
    return (dest);
}

/*
\fn char *load_files(char *path)
\brief load file into buffer
\param path the file path to open\return
\return buffer of file content
*/

char *load_file(char *path)
{
    char *buffer = clean_alloc(2);
    char *line = clean_alloc(20);
    int fd = 0;
    int r = 0;

    DEBUG_MODE == 1 ? debug_log("load_file()", path) : 0;
    fd = open(path, O_RDONLY);
    while (1) {
        r = read(fd, line, 1);
        if (r == -1 || r == 0)
            break;
        buffer = append(buffer, line);
    }
    return (buffer);
}