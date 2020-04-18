/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** main scene prototype
*/

#ifndef SCENE_H_
#define SCENE_H_

#include "game_struct.h"

// main_scene.c

int main_scene_load(game_t *game);
int main_scene_loop(game_t *game, sfClock *timer);
void main_scene_update(game_t *game);

// load_entities.c

entities_t *load_entities_scene(int zombie);

// set_zombie_anim.c

void set_zombie_animation(entities_t *entities);
void set_zombie_key_static(entities_t *entities);
void set_zombie_key_move(entities_t *entities);
void set_zombie_key_attack(entities_t *entities);

// set_player_animation.c

void set_player_animation(entities_t *entities);
void set_player_key_static(entities_t *entities);
void set_player_key_move(entities_t *entities);
void set_player_key_knife(entities_t *entities);
void set_player_key_rifle(entities_t *entities);

#endif /* !SCENE_H_ */
