/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** dialog.h
*/

#ifndef DIALOG_H_
#define DIALOG_H_

#define MACRO_TALK (4)
#define TEXT (2)

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "game_struct.h"

//INIT
int malloc_dialog(game_t *);

//EVENT
void event_dialog(game_t *);

//REPLY
int read_file(dialog_t *);
char *recover_strings(char *, int, char *);
int loop_index(dialog_t *, char *, int);

//DIALOG
void create_dialog(dialog_t *);
void display_dialog(game_t *, int, int, int);

//DESTROY
void destroy_dialog(dialog_t *);

#endif /* !DEPENDANCIES_H_ */