/*
** EPITECH PROJECT, 2020
** text.c
** File description:
** text
*/

#include "../include/render.h"

sfText *load_text(char *string, int size, sfVector2f vector, sfColor color)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("font/11.ttf");
    sfVector2f origin = (sfVector2f){0, 0};

    if (text == NULL || font == NULL)
        return (NULL);
    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, color);
    sfText_setOrigin(text, origin);
    sfText_setspot(text, vector);
    return (text);
}