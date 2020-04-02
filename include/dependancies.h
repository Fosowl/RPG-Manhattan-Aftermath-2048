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
#include "dialog.h"
#include "game_struct.h"


//INIT GAME
int starting_the_game(void);
int malloc_dialog(game_t *);

//EVENT
void manage_event(sfRenderWindow *, game_t *);


#endif /* !DEPENDANCIES_H_ */
