/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** init_menu.c
*/

#include "render.h"
#include "dependancies.h"
#include "game_struct.h"
#include "menu.h"

void init_menu_pos(menu_t *menu)
{
    menu->play_pos.x = 400;
    menu->play_pos.y = 800;
    menu->quit_pos.x = 1100;
    menu->quit_pos.y = 800;
}

static void play_music_menu(char *path)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(path);
    sfSound *sound = sfSound_create();

    sfSound_setBuffer(sound, buffer);
    sfSound_setLoop(sound, true);
    sfSound_setVolume(sound, 65);
    sfSound_play(sound);
}

void init_menu(menu_t *menu)
{
    init_menu_pos(menu);
    play_music_menu("./music/music_menu.ogg");
    menu->menu_texture = sfTexture_createFromFile("assets/back.jpg",
    NULL);
    menu->menu_sprite = sfSprite_create();
    sfSprite_setTexture(menu->menu_sprite, menu->menu_texture, sfTrue);
    menu->play_texture = sfTexture_createFromFile("assets/menu/play.png",
    NULL);
    menu->play_sprite = sfSprite_create();
    sfSprite_setTexture(menu->play_sprite, menu->play_texture, sfTrue);
    sfSprite_setPosition(menu->play_sprite, menu->play_pos);
    menu->quit_texture = sfTexture_createFromFile("assets/menu/quit.png",
    NULL);
    menu->quit_sprite = sfSprite_create();
    sfSprite_setTexture(menu->quit_sprite, menu->quit_texture, sfTrue);
    sfSprite_setPosition(menu->quit_sprite, menu->quit_pos);
}

void init_screen(screen_t *screen)
{
    screen->mode.width = 1920;
    screen->mode.height = 1080;
    screen->mode.bitsPerPixel = 32;
    screen->window = sfRenderWindow_create(screen->mode,
    "Manhattan Aftermath 2048", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(screen->window, 60);
}
