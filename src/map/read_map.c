/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** background_map.c
*/

#include "dependancies.h"
#include "game_struct.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int def_sizemap(char ** av)
{
    struct stat size;
    int len = 0;

    stat(av[1], &size);
    len = size.st_size;
    return (len);
}

char *read_map(char **av)
{
    int fd = 0;
    int len = def_sizemap(av);
    char *buffer = malloc(sizeof(char) * len + 1);
    int size = 0;

    fd = open(av[1], O_RDONLY);
    if (fd == 0 || fd == -1)
        return (84);
    size = read(fd, buffer, len);
    if (size == 0)
        return (84);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}

int load_map(char **av, entities_t *object_list)
{
    char *stock_map = read_map(av);
    char **map = NULL; //fonction lib martin

    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            switch (map[y][x]) {
                case '0':
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/X.png", "map:border_left", false);
                starset_entities_teleport(object_list, "border_left",
                x * 150, y * 150);
                break;
                case '1':
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/4.png", "map:down_wall", false);
                starset_entities_teleport(object_list, "down_wall",
                x * 150, y * 150);
                break;
                case '2':
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/1.png", "map:border_right", false);
                starset_entities_teleport(object_list, "border_right",
                x * 150, y * 150);
                break;
                case '3':
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/3.png", "map:down_right", false);
                starset_entities_teleport(object_list, "down_right",
                x * 150, y * 150);
                break;
               case '4':
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/Z.png", "map:down_left", false);
                starset_entities_teleport(object_list, "down_left",
                x * 150, y * 150);
                break;
            }
        }
    }
    return (0);
}