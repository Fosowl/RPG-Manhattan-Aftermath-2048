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

static int is_alpha(char a)
{
    if ((a <= 'Z' && a >= 'A')
        || (a <= 'z' && a >= 'a')
        || (a <= '9' && a >= '0'))
        return (1);
    else
        return (0);
}

static int count_words(char const *str)
{
    int words = 0;
    int new_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == 0 && new_word == 1)
            new_word = 0;
        else if (is_alpha(str[i]) == 1 && new_word == 0) {
            new_word = 1;
            words++;
        }
    }
    return (words);
}

static int get_new_words(char const *str, char **tab)
{
    int tab_index = 0;
    int sub_tab_index = 0;
    int new_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == 0 && new_word == 1) {
            new_word = 0;
            sub_tab_index = 0;
            tab_index++;
        }
        else if (is_alpha(str[i]) == 1) {
            new_word = 1;
            tab[tab_index][sub_tab_index] = str[i];
            sub_tab_index++;
        }
    }
    return (0);
}

char **my_str_to_word_array(char const *str)
{
    int wc = count_words(str);
    char **tab = malloc(sizeof(char *) * (wc + 1));
    for (int i = 0; i < wc + 1; i++)
        tab[i] = malloc(sizeof(char) * 100);
    get_new_words(str, tab);
    tab[wc] = 0;
    return (tab);
}

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
    char **map = my_str_to_word_array(stock_map);
    char *name = NULL;
    int nb = 0;
    entities_t *tmp = NULL;

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
            }
        }
    }
    while ((tmp = starset_get_next(object_list, "map"))) {
        printf("%s, %f, %f\n",tmp->name, tmp->spot.x, tmp->spot.y);
        tmp->is_trigger = true;
    }
    return (0);
}