/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** loading_bar
*/

#include "render.h"

void loading_bar(sfRenderWindow *window, sfVector2u position
, int life, char *resource)
{
    framebuffer_t *frame_1 = framebuffer_create(1200, 768);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_create(1200, 768);
    sfVector2f size_1 = (sfVector2f){600, 100};
    sfVector2f size_2 = (sfVector2f){507, 70};
    sfVector2f size_3 = (sfVector2f){life, 70};
    sfText *text = load_text(resource, 50, size_2, BLACK);
    sfVector2u new;

    new.x = position.x - 3;
    new.y = position.y - 3;
    my_draw_square(frame_1, new, size_1, WHITE);
    my_draw_square(frame_1, position, size_2, RED);
    my_draw_square(frame_1, position, size_3, GREEN);
    sfTexture_updateFromPixels(texture, frame_1->pixels, 1200, 768, 0, 0);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_drawText(window, text, NULL);
}