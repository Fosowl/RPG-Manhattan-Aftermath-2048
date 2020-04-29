/*
** EPITECH PROJECT, 2019
** paint.c
** File description:
** function to print on screen with pixel
*/

#include "../include/render.h"

int my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y
, sfColor color)
{
    buffer->pixels[4*(y*buffer->width+x)] = color.r;
    buffer->pixels[4*(y*buffer->width+x)+1] = color.g;
    buffer->pixels[4*(y*buffer->width+x)+2] = color.b;
    buffer->pixels[4*(y*buffer->width+x)+3] = color.a;
    return (0);
}

void my_draw_square(framebuffer_t *framebuffer, sfVector2u spot,
sfVector2f size, sfColor color)
{
    for (unsigned int i = spot.y; i < size.y + spot.y; i++) {
        for (unsigned int k = spot.x; k < size.x + spot.x; k++)
            my_put_pixel(framebuffer, k, i, color);
    }
}

void my_draw_circle_pit(sfVector2f spot, sfColor color
, float radius, sfRenderWindow *window)
{
    sfCircleShape *circle;
    sfVector2f vector;
    int t = 0;

    circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setRadius(circle, radius / 20);
    while (t < 360) {
        vector.x = radius * cos(t) + spot.x;
        vector.y = radius * sin(t) + spot.y;
        sfCircleShape_setspot(circle, vector);
        sfRenderWindow_drawCircleShape(window, circle, NULL);
        t++;
    }
    sfCircleShape_destroy(circle);
}