/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** init_reply.c
*/

#include "dialog.h"

int def_sizemap(char *name)
{
    struct stat size = {0};
    int len = 0;

    stat(name, &size);
    len = size.st_size;
    return (len);
}

int name(dialog_t *dialog, char *reply, int i)
{
    if (reply[i + 1] != '"') {
        write(0, "ERROR 1 in reply.json: expected '""' around the name\n", 54);
        return (84);
    } else {
        dialog->talk = -1;
        i = loop_index(dialog, reply, i);
        if (i == 84)
            return (84);
    }
    return (i);
}

int manage_reply(dialog_t *dialog, char *reply)
{
    int i = 0;

    if (reply[i] != '{')  {int parsing_reply(dialog_t *dialog, char *reply);
        write(0, "ERROR 0 in reply.json: expected '{' in start of file\n", 51);
        return (84);
    } else {
        i += 5;
        i = name(dialog, reply, i);
        if (i == 84)
            return (84);
    }
    dialog->person = 0;
    return (0);
}

int read_file(dialog_t *dialog)
{
    int fd = 0;
    char *reply = NULL;
    int size = 0;
    int len = def_sizemap("reply.json");

    reply = malloc(sizeof(char) * len + 1);
    if (reply == NULL)
        return (84);
    fd = open("reply.json", O_RDONLY);
    if (fd == 0 || fd == -1)
        return (84);
    size = read(fd, reply, len);
    if (size == 0)
        return (84);
    reply[len] = '\0';
    if (manage_reply(dialog, reply) == 84)
        return (84);
    close(fd);
    return (0);
}

char *recover_strings(char *reply, int i, char *add)
{
    int a = 0;

    for (; reply[i] != '"'; i++) {
        if ((reply[i] == '\\') && (reply[i + 1] == 'n')) {
            add[a] = '\n';
            i++;
        } else
            add[a] = reply[i];
        a++;
    }
    return (add);
}