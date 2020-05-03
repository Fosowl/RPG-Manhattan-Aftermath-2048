/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** background_map.c
*/

#include "dependancies.h"
#include "game_struct.h"
#include "warlock.h"
#include "scene.h"

char *read_map(void)
{
    int fd = 0;
    char *buffer = malloc(sizeof(char) * 1000);
    int size = 0;

    fd = open("map.txt", O_RDONLY);
    if (fd == 0 || fd == -1)
        return (NULL);
    size = read(fd, buffer, 1000);
    if (size == 0)
        return (NULL);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}

char *add_obj(int nb, char *origin)
{
    char *name = NULL;

    name = append(origin, my_itoa(nb));
    return (name);
}

entities_t *create_new_obj(entities_t *object_list, int x, int y, char **map)
{
    static int nb = 0;
    char *origin = NULL;
    char *name = NULL;
    char *path = NULL;

    origin = check_origin_ground(map, x, y);
    if (origin == NULL)
        return (NULL);
    path = check_path_ground(map, x, y);
    name = append(origin, my_itoa(nb));
    object_list = starset_entities_add(object_list, path, name, true);
    starset_entities_teleport(object_list, name, x * 150, y * 150);
    nb++;
    return (object_list);
}

entities_t *check_entities(entities_t *object_list, int y, char **map)
{
    entities_t *a = NULL;

    for (int x = 0; map[y][x] != '\0'; x++) {
        a = create_new_obj(object_list, x, y, map);
        if (a == NULL)
            continue;
        else
            object_list = a;
    }
    return (object_list);
}

entities_t *load_map(entities_t *object_list)
{
    char *stock_map = read_map();
    char **map = divide_array(stock_map, '\n');

    for (int y = 0; map[y] != NULL; y++)
        object_list = check_entities(object_list, y, map);
    return (object_list);
}
