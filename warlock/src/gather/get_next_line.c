/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** get next line project file
*/

#include <stdio.h>
#include <stdlib.h>
#include "warlock.h"

static int check_end(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\n')
            return (1);
    }
    return (0);
}

static char *get_current_line(int fd, char *line, char *buffer)
{
    int r = 1;

    while (check_end(line) != 1 && r != 0) {
        for (int i = 0; i < 1; i++)
            buffer[i] = '\0';
        r = read (fd, buffer, 1);
        if (r <= 0)
            break;
        line = append(line, buffer);
    }
    if (r <= 0)
        return (NULL);
    return (line);
}

char *get_next_line(int fd)
{
    char *buffer = malloc(sizeof(char) * 1 + 5);
    char *line = malloc(sizeof(char) * 1 + 1);
    static char back[1 + 1];
    int i;
    int f = 0;

    if (fd == -1 || 1 <= 0 || buffer == NULL || line == NULL)
        return (NULL);
    if (my_strlen(back) > 0)
        for (int a = 0; a < 1 + 1; a++)
            back[a] = '\0';
    line = append(line, back);
    if (!(line = get_current_line(fd, line, buffer)))
        return (NULL);
    buffer = cut_tail(buffer, '\n');
    for (i = 0; buffer[i] != '\0'; i++, back[i + 1] = '\0')
        back[i] = buffer[i];
    for (; line[f] != '\n' && line[f] != '\0'; f++);
    line[f] = '\0';
    return (line[0] == '\0' ? NULL : line);
}