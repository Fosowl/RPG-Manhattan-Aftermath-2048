/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** menu.h
*/

#ifndef MENU_H_
#define MENU_H_

#include "dependancies.h"

void init_menu(menu_t *menu);
int menu_loop(game_t *game);
void destroy_menu(game_t *game);
void init_struct(game_t *game);
void init_screen(screen_t *screen);

#endif /* !MENU_H_ */