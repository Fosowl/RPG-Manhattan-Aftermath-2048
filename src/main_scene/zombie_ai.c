/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** zombie_ai
*/

#include "game_struct.h"
#include "scene.h"
#include "starset_engine.h"
#include "game_macro.h"
#include "warlock.h"
#include "path.h"

static void zombie_visit_area(entities_t *tmp, int *c)
{
    int sign = -1;
    static sfVector2f new[350];

    if (rand() % 2)
        sign = 1;
    if (rand() % 300 == 7 || new[*c].x == 0.0f) {
        new[*c].x = tmp->spot.x  + rand() % 300 * sign;
        new[*c].y = tmp->spot.y + rand() % 300 * sign;
    }
    starset_entities_move(tmp, tmp->name, new[*c].x, new[*c].y);
    starset_entities_rotate_to(tmp, tmp->name, new[*c]);
    starset_play_animation(tmp, tmp->name, "static", 4);
    *c += 1;
}

static void zombie_attack_player(entities_t *tmp, int *pass, player_t *player)
{
    *pass = starset_play_animation(tmp, tmp->name, "attack", 6);
    starset_entities_rotate_to(tmp, tmp->name
    , player->save->spot);
    if (*pass == 0)
        player->save->life -= 1;
}

void blood_effect(entities_t **blood, entities_t *tmp)
{
    static int id = 0;
    int r = rand() % 3;
    char *name = fill("blood:");

    name = append(name, my_itoa(id));
    *blood = starset_entities_add(*blood, BLOOD_PATH, name, true);
    starset_add_animation(*blood, name, "basic", (sfVector2u){41, 49});
    if (r == 3)
        starset_add_animation_key(*blood, name, "basic", v_2f{105.0f, 101.0f});
    else if (r == 2)
        starset_add_animation_key(*blood, name, "basic", v_2f{64.0f, 50.0f});
    else
        starset_add_animation_key(*blood, name, "basic", v_2f{5.0f, 100.0f});
    starset_play_animation(*blood, name, "basic", 4);
    starset_entities_teleport(*blood, name, tmp->spot.x, tmp->spot.y);
    starset_entities_get_propreties(*blood, name)->is_trigger = true;
    id++;
}

static int handle_zombie_damage(entities_t **entities, entities_t *tmp
, entities_t **entities_runtime)
{
    if (tmp->collision && search("bullet", tmp->collision->name) != -1
    && tmp->collision->visible == true) {
        tmp->life -= tmp->collision->life;
        tmp->collision->visible = false;
        starset_entities_play_sound(tmp, tmp->name, "pain", false);
        blood_effect(entities_runtime, tmp);
    }
    if (tmp->life <= 5 && search("zombie", tmp->name) != -1)
        starset_entities_play_sound(tmp, tmp->name, "death", false);
    if (tmp->life <= 0 && search("zombie", tmp->name) != -1) {
       * entities = starset_entities_destroy(*entities, tmp->name);
        return (1);
    }
    return (0);
}

void zombie_ai(entities_t **entities, player_t *player
, entities_t **entities_runtime)
{
    int distance = 0;
    entities_t *tmp = NULL;
    int c = 0;
    int pass = 0;

    while ((tmp = starset_get_next(*entities, "zombie"))) {
        if (handle_zombie_damage(entities, tmp, entities_runtime) == 1)
            continue;
        distance = starset_get_distance(tmp->spot, player->save->spot);
        if (distance < 100) {
            zombie_attack_player(tmp, &pass, player);
        } else if (distance < 350 * player->noise && distance > 80*
        player->noise) {
            starset_play_animation(tmp, tmp->name, "static", 6);
            starset_entities_move_to_other(*entities, tmp->name
            , player->save->name);
            starset_entities_rotate_to(tmp, tmp->name, player->save->spot);
        } else
            zombie_visit_area(tmp, &c);
    }
}