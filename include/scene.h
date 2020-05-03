/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** main scene prototype
*/

#ifndef SCENE_H_
#define SCENE_H_

#include "game_struct.h"

// load_scene.c

int main_scene_load(game_t *game);

// main_scene.c

int main_scene_loop(game_t *game, sfClock *timer);
int main_scene_update(game_t *game);
void play_music(char *path);

// load_entities.c

entities_t *load_entities_scene(int zombie, sfRenderWindow *window);
entities_t *load_map(entities_t *object_list, int *err);

// set_zombie_anim.c

void set_zombie_animation(entities_t *entities);
void set_zombie_key_static(entities_t *entities);
void set_zombie_key_move(entities_t *entities);
void set_zombie_key_attack(entities_t *entities);

// set_player_animation.c

void set_player_animation(entities_t *entities);

// set_player_static.c

void set_player_key_torch_static(entities_t *entities);
void set_player_key_pistol_static(entities_t *entities);
void set_player_key_rifle_static(entities_t *entities);
void set_player_key_knife_static(entities_t *entities);

// set_sound.ogg

void set_zombie_sound(entities_t *entities, int nb_zombie);
void set_player_sound(entities_t *entities);
void set_girl_sound(entities_t *entities);

// control.c

void player_controller(game_t *game);
int teleport_player_up(entities_t *entities, entities_t *save
, entities_t *ground);
int teleport_player_down(entities_t *entities, entities_t *save
, entities_t *ground);
int teleport_player_left(entities_t *entities, entities_t *save
, entities_t *ground);
int teleport_player_right(entities_t *entities, entities_t *save
, entities_t *ground);

// toggle_object.c

void player_switch_object(entities_t *entities, player_t player);

// p_move_anim.c

void set_player_key_pistol_move(entities_t *entities);
void set_player_key_rifle_move(entities_t *entities);
void set_player_key_knife_move(entities_t *entities);

// p_attack_anim.c

void set_player_key_pistol_attack(entities_t *entities);
void set_player_key_rifle_attack(entities_t *entities);
void set_player_key_knife_attack(entities_t *entities);
void set_player_key_pistol_reload(entities_t *entities);
void set_player_key_rifle_reload(entities_t *entities);

// player_attack.c

int attack_entities(game_t *game, sfEvent *event
, sfRenderWindow *window);
int on_attack(game_t *game, char *animation, int *r);

// object_sound.c

void handle_zombie_sound(game_t *game);
void handle_player_sound(game_t *game);

// zombie_ai.c

void zombie_ai(entities_t **entities, player_t *player
, entities_t **entities_runtime);
void blood_effect(entities_t **blood, entities_t *tmp);

// update_object.c

int update_value(game_t *game);
void update_object(game_t *game);

// spawn_point.c

sfVector2f *zombie_spawn_point(int nb_zombie);

// dog_anim.c

void set_dog(entities_t *entities);
void move_dog(entities_t *entities, entities_t *player, sfVector2f girl);
// ui.c

void update_ui(game_t *game);

// set_girl.c

void set_girl_animation(entities_t *entities);

// zombie_loading.c

void update_zombie_loading(sfRenderWindow *window, int v, int max_v);

entities_t *create_zombie_scene(entities_t *entities, int zombie
, sfRenderWindow *window);

void draw_loading_text(sfRenderWindow *window);

// girl_ai.c

void girl_ai(game_t *game);

//pause.c

sfBool manage_event(game_t *game);

// load_ground.c

entities_t *load_ground(entities_t *entities, int nb);

// PICK_OBJECT.C

entities_t *load_pick_object(entities_t *entities, int nb);
void pick_item(game_t *game);

// scene.h

void introduction_scene(game_t *game);

char *check_path_ground(char **map, int x, int y);
char *check_origin_ground(char **map, int x, int y);

#endif /* !SCENE_H_ */
