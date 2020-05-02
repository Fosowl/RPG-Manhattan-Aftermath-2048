/*
** EPITECH PROJECT, 2019
** initialize.c
** File description:
** usefull function
*/

#include "warlock.h"

char *clean_alloc(int size)
{
    char *str = NULL;

    str = malloc(size * sizeof(char));
    if (str == NULL) {
        put_error("allocation error !");
        return (NULL);
    }
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}

char *fill(char *with)
{
    int i = 0;
    char *this = NULL;

    this = clean_alloc(sizeof(char) * my_strlen(with) + 2);
    if (this == NULL)
        return (NULL);
    for (i = 0; with[i] != '\0'; i++)
        this[i] = with[i];
    this[i] = '\0';
    return (this);
}

char **fill_double(char **temp)
{
    int	i = 0;
    int o = 0;
    int nb = array_lenght(temp);
    char **dest = clean_double_alloc(nb + 1, my_strlen(temp[0]) + 1);

    DEBUG_MODE == 1 ? debug_log("fill_double() arg", temp) : 0;
    while (o < nb) {
        while (temp[o][i] != '\0') {
            dest[o][i] = temp[o][i];
            i = i + 1;
        }
        dest[o][i] = '\0';
        i = 0;
        o += 1;
    }
    return (dest);
}

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