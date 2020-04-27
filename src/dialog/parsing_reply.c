/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** parsing_reply.c
*/

#include "dialog.h"

int find_speech(dialog_t *dialog, char *reply, int i)
{
    char *speech = NULL;

    speech = malloc(sizeof(char) * 256);
    if (speech == NULL)
        return (84);
    speech[255] = '\0';
    if (reply[i] != '"') {
        write(0, "ERROR 5 in reply.json: expected '""' around the speech\n",
                                                                        56);
        return (84);
    } else {
        i++;
        speech = recover_strings(reply, i, speech);
        for (; reply[i] != '"'; i++);
        dialog->text[dialog->personage][dialog->nb_speech] = speech;
    }
    return (i);
}

int loop_speech(dialog_t *dialog, char *reply, int i)
{
    while (1) {
        dialog->nb_speech++;
        i++;
        for (; reply[i] != '"'; i++);
        i += 3;
        i = find_speech(dialog, reply, i);
        if (i == 84)
            return (84);
        i++;
        if (reply[i] == ',')
            i += 2;
        else if ((reply[i + 6] != '\n' && reply[i + 5] == '}')
                || (reply[i + 8] == '\0')) {
            i += 5;
            break;
        }
        i += 9;
    }
    return (i);
}

int find_index(dialog_t *dialog, char *reply, int i)
{
    if (reply[i] != '"') {
        write(0, "ERROR 4 in reply.json: expected '""' around the index\n", 55);
        return (84);
    } else {
        dialog->nb_speech = -1;
        i = loop_speech(dialog, reply, i);
        if (i == 84)
            return (84);
    }
    return (i);
}

int check_index(dialog_t *dialog, char *reply, int i)
{
    if (reply[i] != '{') {
        write(0, "ERROR 2 in reply.json: expected '{' in start of speech", 53);
        write(0, " or there is no speech\n", 22);
        return (84);
    } else {
        for (; reply[i] != '"'; i++);
        i = find_index(dialog, reply, i);
        if (i == 84)
            return (84);
        i += 6;
        if (reply[i + 5] == '\0')
            return (i);
        if (reply[i + 6] != '\n' && reply[i + 5] == '}')
            return (i);
    }
    return (i);
}

int loop_index(dialog_t *dialog, char *reply, int i)
{
    while (reply[i] != '\0') {
        dialog->personage++;
        i += 2;
        for (; reply[i] != '"'; i++);
        i += 3;
        i = check_index(dialog, reply, i);
        if (i == 84)
            return (84);
        if (reply[i + 5] == '\0')
            break;
        if (reply[i + 6] != '\n' && reply[i + 5] == '}')
            break;
    }
    return (i);
}