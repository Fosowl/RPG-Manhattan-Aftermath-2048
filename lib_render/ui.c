/*
** EPITECH PROJECT, 2020
** render_lib
** File description:
** ui
*/

#include "render.h"

void life_bar(sfRenderWindow *window, sfVector2u position, int life
, sfVector2i screen_size)
{
    framebuffer_t *frame_1 = framebuffer_create(screen_size.x, screen_size.y);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture;
    sfVector2f size_2 = (sfVector2f){57, 7};
    sfVector2f size_3 = (sfVector2f){57.0f * ((float)life / 100.0f), 7};

    my_draw_square(frame_1, position, size_2, RED);
    my_draw_square(frame_1, position, size_3, GREEN);
    texture = sfTexture_create(screen_size.x, screen_size.y);
    sfTexture_updateFromPixels(texture, frame_1->pixels
    , screen_size.x, screen_size.y, 0, 0);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    free(frame_1);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}