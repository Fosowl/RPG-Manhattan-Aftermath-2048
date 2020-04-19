/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** player attack animation
*/

#include "starset_engine.h"
#include "scene.h"
#include "game_macro.h"

void set_player_key_pistol_attack(entities_t *entities)
{
    add_key(entities, "player", "pistol:attack", v_2f{23.0f, 507.0f});
    add_key(entities, "player", "pistol:attack", v_2f{111.0f, 507.0f});
    add_key(entities, "player", "pistol:attack", v_2f{191.0f, 507.0f});
}

void set_player_key_rifle_attack(entities_t *entities)
{
    add_key(entities, "player", "rifle:attack", v_2f{32.0f, 761.0f});
    add_key(entities, "player", "rifle:attack", v_2f{132.0f, 761.0f});
    add_key(entities, "player", "rifle:attack", v_2f{234.0f, 761.0f});
}

void set_player_key_knife_attack(entities_t *entities)
{

}

void set_player_key_pistol_reload(entities_t *entities)
{

}

void set_player_key_rifle_reload(entities_t *entities)
{

}