/*
** EPITECH PROJECT, 2020
** warlock-C-libraries
** File description:
** dependancies for function.
*/

#ifndef DEPENDANCIES_H_
#define DEPENDANCIES_H_

#include "warlock.h"

// handle_case.c

int handle_case(void *string);
int get_expection(int nb);
void fusion_2(char *endCopy, char *str, char *sticked, int i);

// emultator

int emulate_else_if(int *pass, int true_condition);

// debug

void debug_log(char *text, void *adress);

#define SWITCH_W int pass = 1;
#define CASE_O if (emulate_else_if(&pass, 
#define CASE_C ))
#define DEFAULT_W pass > 0 ? 0 :

#endif /* !DEPENDANCIES_H_ */
