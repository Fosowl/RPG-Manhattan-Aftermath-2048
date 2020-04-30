/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** background_map.c
*/

#include "dependancies.h"
#include "game_struct.h"
#include "warlock.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *read_map(void)
{
    int fd = 0;
    char *buffer = malloc(sizeof(char) * 1000);
    int size = 0;

    fd = open("map.txt", O_RDONLY);
    if (fd == 0 || fd == -1)
        return (84);
    size = read(fd, buffer, 1000);
    if (size == 0)
        return (84);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}

int load_map(entities_t *object_list)
{
    char *stock_map = read_map();
    char **map = divide_array(stock_map, "\n");

    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            switch (map[y][x]) {
                case '0':
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/X.png", "map:border_left", false);
                starset_entities_teleport(object_list, "map:border_left",
                x * 150, y * 150);
                break;
                case '1':
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/4.png", "map:down_wall", false);
                starset_entities_teleport(object_list, "map:down_wall",
                x * 150, y * 150);
                break;
                case '2':
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/1.png", "map:border_right", false);
                starset_entities_teleport(object_list, "map:border_right",
                x * 150, y * 150);
                break;
                case '3':
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/3.png", "map:down_right", false);
                starset_entities_teleport(object_list, "map:down_right",
                x * 150, y * 150);
                break;
                case '4':
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/Z.png", "map:down_left", false);
                starset_entities_teleport(object_list, "map:down_left",
                x * 150, y * 150);
                break;
            }
        }
    }
    return (0);
}