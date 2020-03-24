/*
** EPITECH PROJECT, 2019
** defender
** File description:
** function to move sprite
*/

#include "render.h"

float angle_to_sprite(sfVector2f from, sfVector2f to)
{
    sfVector2f vector = (sfVector2f){0.0f, 0.0f};
    float angle = 0.0f;

    vector.x = to.x - from.x;
    vector.y = to.y - from.y;
    angle = atan2(vector.y, vector.x) * 57;
    return (angle);
}

void move_from_angle(sfVector2f *vector, float angle, float average_speed)
{
    float distance = 100.0f;
    sfVector2f speed = (sfVector2f){0.0f, 0.0f};

    speed.x = 2 * cos(angle) * average_speed;
    speed.y = 2 * sin(180 - (angle + 90)) * average_speed;
    vector->y += speed.y;
    vector->x += speed.x;
}

float move_sprite(sfVector2f *from, sfVector2f *to, float average_speed)
{
    sfVector2f vector = (sfVector2f){0.0f, 0.0f};
    float angle = 0.0f;
    float distance = 100.0f;
    sfVector2f speed = (sfVector2f){0.0f, 0.0f};

    vector.x = to->x - from->x;
    vector.y = to->y - from->y;
    distance = sqrt(pow(vector.y, 2) + pow(vector.x, 2));
    if (distance >= 15.0f) {
        angle = atan2(vector.y, vector.x) * 57;
        speed.x = 2 * cos(angle) * average_speed;
        speed.y = 2 * sin(180 - (angle + 90)) * average_speed;
        from->y += speed.y;
        from->x += speed.x;
    }
    return (angle);
}
