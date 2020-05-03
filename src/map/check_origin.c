/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** check_origin.c
*/

#include "dependancies.h"
#include "game_struct.h"
#include "warlock.h"
#include "scene.h"

char *check_origin_corner(char **map, int x, int y, char *origin)
{
    switch (map[y][x])
    {
    case '0':
        origin = "map:border_left";
        break;
    default:
        return (NULL);
    }
    printf("4\n");
    return (origin);
}

char *check_origin_object(char **map, int x, int y, char *origin)
{
    switch (map[y][x])
    {
    case '7':
        origin = "assets/inventory/info_water.png";
        break;
    case '8':
        origin = "assets/inventory/info_canned.png";
        break;
    case '9':
        origin = "assets/inventory/info_apple.png";
        break;
    default:
        origin = check_origin_corner(map, x, y, origin);
        break;
    }
    printf("3\n");
    return (origin);
}

char *check_origin_wall(char **map, int x, int y, char *origin)
{
    switch (map[y][x])
    {
    case '4':
        origin = "map:down_left";
        break;
    case '5':
        origin = "map:ground";
        break;
    case '6':
        origin = "assets/inventory/info_steak.png"; //change
        break;
    default:
        origin = check_origin_object(map, x, y, origin);
        break;
    }
    printf("2\n");
    return (origin);
}

char *check_origin_ground(char **map, int x, int y)
{
    char *origin = NULL;

    switch (map[y][x])
    {
    case '1':
        origin = "map:down_wall";
        break;
    case '2':
        origin = "map:border_right";
        break;
    case '3':
        origin = "map:down_right";
        break;
    default:
        origin = check_origin_wall(map, x, y, origin);
        break;
    }
    printf("1\n");
    return (origin);
}