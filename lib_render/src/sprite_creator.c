/*
** EPITECH PROJECT, 2019
** creation.c
** File description:
** function to create / set CSFML structure
*/

#include "../include/render.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *frame = malloc(sizeof(framebuffer_t));
    frame->width = width;
    frame->height = height;
    frame->pixels = malloc(width * height * 4);
    return (frame);
}

object_t *create_object(char *path, float x, float y, float angle)
{
    object_t *object = malloc(sizeof(object_t));
    sfVector2u size;

    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(object->sprite, object->texture, sfFalse);
    size = sfTexture_getSize(object->texture);
    object->visible = 1;
    object->rotation = angle;
    object->spot = (sfVector2f){x, y};
    object->origin = (sfVector2f){size.x / 2, size.y / 2};
    object->weight = sqrt((size.x * size.y)) / 2;
    object->hitbox.left = object->spot.x - object->origin.x;
    object->hitbox.height = size.y;
    object->hitbox.top = object->spot.y - object->origin.y;
    object->hitbox.width = size.x;
    sfSprite_setOrigin(object->sprite, object->origin);
    sfSprite_setPosition(object->sprite, object->spot);
    sfSprite_setRotation(object->sprite, angle);
    return (object);
}