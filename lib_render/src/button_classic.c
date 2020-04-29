/*
** EPITECH PROJECT, 2020
** render_lib
** File description:
** interact
*/

#include "../include/render.h"

button_t *create_button(char *path, sfVector2f spot, char *text, int s)
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f text_spot;
    sfColor color = GLASS_RED;
    int size = (my_strlen(text) * s) * 6;

    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    button->rect.width = size;
    button->start_size = size;
    button->rect.height = s * 10;
    button->spot.x = spot.x - (button->rect.width / 2);
    button->spot.y = spot.y - (button->rect.height / 2);
    text_spot.x = button->spot.x + s * 2;
    text_spot.y = button->spot.y - s * 2;
    button->text_size = s * 10;
    button->text = load_text(text, size, text_spot, color);
    sfSprite_setPosition(button->sprite, button->spot);
    return (button);
}

void resize_button(int center_left, int center_top, button_t *button)
{
    if (center_left == 1 && center_top == 1 &&
    button->rect.width < button->start_size + 5) {
        button->rect.height += 1;
        button->rect.width += 1;
        button->text_size += 1;
        if (button->rect.left < 50)
            button->rect.left += rand() % 3;
        else
            button->rect.left -= rand() % 3;
        if (button->rect.top < 50)
            button->rect.left += rand() % 3;
        else
            button->rect.left -= rand() % 3;
    } else if (button->rect.width >= button->start_size) {
        button->rect.height -= 1;
        button->rect.width -= 1;
        button->text_size -= 1;
    }
}

int button_render_and_check(sfRenderWindow *window, sfEvent *event
, button_t *button)
{
    sfVector2i mouse;
    int center_left = 0;
    int center_top = 0;

    mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > button->spot.x &&
    mouse.x < button->spot.x + button->rect.width)
        center_left = 1;
    if (mouse.y > button->spot.y &&
    mouse.y < button->spot.y + button->rect.height)
        center_top = 1;
    resize_button(center_left, center_top, button);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfText_setCharacterSize(button->text, button->text_size);
    sfRenderWindow_drawSprite(window, button->sprite, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
    if (center_left == 1 && center_top == 1 && event->type == 9)
        return (1);
    else
        return (0);
}