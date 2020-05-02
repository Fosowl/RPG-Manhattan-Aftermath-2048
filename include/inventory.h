/*
** EPITECH PROJECT, 2019
** PROJECT-011
** File description:
** inventory.h
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#define AK47 (0)
#define GUN (1)
#define KNIFE (2)
#define BULLET_AK47 (3)
#define BULLET_GUN (4)
#define STEAK (5)
#define WATER (6)
#define APPLE (7)
#define CANNED (8)
#define BANDAGE (9)
#define MEDICAL_KIT (10)

int malloc_inventory(game_t *game);
void create_button_inventory(inventory_t *inventory);
void create_case_element(inventory_t *inventory);
void display_case_element(game_t *game);
int event_button_inventory(game_t *game);
void create_nb_element(inventory_t *inventory);
char *object_arms_option(inventory_t *inventory, int i);
basic_object_t *init_element(inventory_t *inventory, int i, int x, int y);
void display_nb_element(game_t *game, int);
void display_element(game_t *game, int i);
void update_element(game_t *game);
void nb_case_for_type(inventory_t *inventory, int i, int class);
void option_for_class(inventory_t *inventory, int i);
void check_for_draw(inventory_t *inventory, int i);
void add_new_value(inventory_t *inventory, int i);
void create_element(inventory_t *inventory);
void element_for_start(inventory_t *inventory);
void init_items_for_start_of_game(inventory_t *inventory);
void type_of_object(inventory_t *inventory, int i);
void new_value_contains(inventory_t *inventory);
void destroy_inventory(game_t *game);
sfBool pause_inventory(sfRenderWindow *window, sfEvent *event, game_t *game);

#endif