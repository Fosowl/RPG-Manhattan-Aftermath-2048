/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** inventory.h
*/

#ifndef GAME_STRUCT_H_
#define GAME_STRUCT_H_

int malloc_inventory(game_t *game);
void create_button_inventory(inventory_t *inventory);
void create_case_element(inventory_t *inventory);
void display_case_element(game_t *game);
void event_button_inventory(game_t *game);
void create_nb_element(inventory_t *inventory);

#endif