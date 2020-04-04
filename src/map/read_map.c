/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** background_map.c
*/

#include "fonctions.h"

int read_map(char **argv, sfRenderWindow *window, game_t *game,
                sfClock *clock)
{
    int fd = 0;
    int len = def_sizemap(argv);
    char *buffer = malloc(sizeof(char) * len + 1);
    int size = 0;

    fd = open(argv[1], O_RDONLY);
    if (fd == 0 || fd == -1)
        return (84);
    size = read(fd, buffer, len);
    if (size == 0)
        return (84);
    buffer[size] = '\0';
    if (game_loop(window, game, clock, buffer) == 84)
        return (84);
    close(fd);
    return (0);
}

int def_sizemap(char ** argv)
{
    struct stat size;
    int len = 0;

    stat(argv[1], &size);
    len = size.st_size;
    return (len);
}

int parsing_map(char *buffer, game_t *game)
{
    int nb_ground = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '1')
            nb_ground++;
    }
    game->ground = malloc(sizeof(basicobject_t) * nb_ground);
    if (game->ground == NULL)
        return (84);
    game->ground->pg_x = malloc(sizeof(int) * nb_ground);
    if (game->ground->pg_x == NULL)
        return (84);
    game->ground->pg_y = malloc(sizeof(int) * nb_ground);
    if (game->ground->pg_y == NULL)
        return (84);
    game->ground->nb = nb_ground;
    map_option(buffer, game);
    pos_object(game);
    create_map(game);
    return (0);
}

void map_option(char *buffer, game_t *game)
{
    int a = 0;
    int index = 0;
    int x = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            index++;
            a = 0;
        }
        if (buffer[i] == '0')
            a++;
        if (buffer[i] == '1') {
            game->ground->pg_x[x] = 100 * a;
            game->ground->pg_y[x] = 60 * index;
            a++;
            x++;
        }
    }
}

void pos_object(game_t *game)
{
    game->ennemie->vector.x = game->ground->pg_x[game->ground->min + 5];
    game->ennemie->vector.y = game->ground->pg_y[game->ground->min + 5] - 80;
    sfSprite_setPosition(game->ennemie->sprite, game->ennemie->vector);
    game->ennemie->vector.x = game->ground->pg_x[game->ground->min + 7];
    game->ennemie->vector.y = game->ground->pg_y[game->ground->min + 1] - 80;
    sfSprite_setPosition(game->ennemie->sprite, game->ennemie->vector);
}