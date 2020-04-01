/*
** EPITECH PROJECT, 2020
** include
** File description:
** dependancies
*/

#ifndef DEPENDANCIES_H_
#define DEPENDANCIES_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "game_struct.h"


#define PERSONAGE (1)
#define TEXT (1)

//INIT GAME
int starting_the_game(void);
int malloc_game(game_t *);

//EVENT
void manage_event(sfRenderWindow *, game_t *);

//DIALOG
int malloc_dialog(dialog_t *);
void create_dialog(dialog_t *);
void display_dialog(sfRenderWindow *, dialog_t *, int personage, int text);


#endif /* !DEPENDANCIES_H_ */
