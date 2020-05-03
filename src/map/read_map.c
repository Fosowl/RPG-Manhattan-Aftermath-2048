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
        return (NULL);
    size = read(fd, buffer, 1000);
    if (size == 0)
        return (NULL);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}

entities_t *load_map(entities_t *object_list, int *error)
{
    char *stock_map = NULL;
    char **map = NULL;
    char *name = NULL;
    int nb = 0;

    //GESTION ERREUR CHANGER DE NOM DU TXT
    if (read_map() == NULL) {
        error = 1;
        return (object_list);
    }
    map = divide_array(stock_map, '\n');

    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; map[y][x] != '\0'; x++) {
            nb++;
            switch (map[y][x]) {
                case '0':
                name = append("map:border_left", my_itoa(nb));
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/X.png", name, true);
                starset_entities_teleport(object_list, name,
                x * 150, y * 150);
                break;
                case '1':
                name = append("map:down_wall", my_itoa(nb));
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/4.png", name, true);
                starset_entities_teleport(object_list, name,
                x * 150, y * 150);
                break;
                case '2':
                name = append("map:border_right", my_itoa(nb));
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/1.png", name, true);
                starset_entities_teleport(object_list, name,
                x * 150, y * 150);
                break;
                case '3':
                name = append("map:down_right", my_itoa(nb));
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/3.png", name, true);
                starset_entities_teleport(object_list, name,
                x * 150, y * 150);
                break;
                case '4':
                name = append("map:down_left", my_itoa(nb));
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/Z.png", name, true);
                starset_entities_teleport(object_list, name,
                x * 150, y * 150);
                break;
                case '5':
                name = append("map:ground", my_itoa(nb));
                object_list = starset_entities_add(object_list,
                "assets/building/Walls/W.png", name, true);
                starset_entities_teleport(object_list, name,
                x * 150, y * 150);
                starset_entities_get_propreties
                (object_list, name)->is_trigger = true;
                break;
            }
        }
    }
    return (object_list);
}
