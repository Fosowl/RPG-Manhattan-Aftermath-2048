/*
** EPITECH PROJECT, 2020
** render_lib
** File description:
** interact
*/

#include "render.h"

button_t *create_simple_button(char *path, sfVector2f position, char *text)
{
    button_t *button = malloc(sizeof(button_t));
    sfVector2f origin;

    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    button->size = sfTexture_getSize(button->texture);
    origin.x = button->size.x / 2;
    origin.y = button->size.y / 2;
    button->position.x = position.x;
    printf("debug sprite>>>%d\n", button->sprite);
    button->position.y = position.y;
    button->text = load_text(text, button->size.x / 3, position, BLACK);
    sfSprite_setOrigin(button->sprite, origin);
    sfSprite_setPosition(button->sprite, button->position);
    return (button);
}

int simple_button_render_and_check(sfRenderWindow *window, sfEvent *event
, button_t *button)
{
    sfVector2i mouse;
    int center_left = 0;
    int center_top = 0;

    mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x > button->position.x - button->size.x
    && mouse.x < button->position.x + button->size.x) {
        center_left = 1;
    }
    if (mouse.y > button->position.y - button->size.y - 90
    && mouse.y < button->position.y + button->size.y - 90) {
        center_top = 1;
    }
    printf("debug sprite>>>%d\n", button->sprite);
    sfRenderWindow_drawSprite(window, button->sprite, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
    if (center_left == 1 && center_top == 1 && event->type == 9)
        return (1);
    else
        return (0);
}