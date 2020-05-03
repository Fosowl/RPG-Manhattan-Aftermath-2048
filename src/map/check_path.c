/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** check_path.c
*/

#include "dependancies.h"
#include "game_struct.h"
#include "warlock.h"
#include "scene.h"

char *check_path_corner(char **map, int x, int y, char *path)
{
    switch (map[y][x])
    {
    case '0':
        path = "assets/building/Walls/X.png";
        break;
    default:
        return (NULL);
    }
    return (path);
}

char *check_path_object(char **map, int x, int y, char *path)
{
    switch (map[y][x])
    {
    case '7':
        path = "assets/inventory/info_water.png";
        break;
    case '8':
        path = "assets/inventory/info_canned.png";
        break;
    case '9':
        path = "assets/inventory/info_apple.png";
        break;
    default:
        path = check_path_corner(map, x, y, path);
        break;
    }
    return (path);
}

char *check_path_wall(char **map, int x, int y, char *path)
{
    switch (map[y][x])
    {
    case '4':
        path = "assets/building/Walls/Z.png";
        break;
    case '5':
        path = "assets/building/Walls/W.png";
        break;
    case '6':
        path = "assets/inventory/info_steak.png";
        break;
    default:
        path = check_path_object(map, x, y, path);
        break;
    }
    return (path);
}

char *check_path_ground(char **map, int x, int y)
{
    char *path = NULL;

    switch (map[y][x])
    {
    case '1':
        path = "assets/building/Walls/4.png";
        break;
    case '2':
        path = "assets/building/Walls/1.png";
        break;
    case '3':
        path = "assets/building/Walls/3.png";
        break;
    default:
        path = check_path_wall(map, x, y, path);
        break;
    }
    return (path);
}