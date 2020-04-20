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
    add_key(entities, "player", "knife:attack", v_2f{10.0f, 248.0f});
    add_key(entities, "player", "knife:attack", v_2f{116.0f, 248.0f});
    add_key(entities, "player", "knife:attack", v_2f{351.0f, 248.0f});
    add_key(entities, "player", "knife:attack", v_2f{563.0f, 248.0f});
    add_key(entities, "player", "knife:attack", v_2f{665.0f, 248.0f});
}

void set_player_key_pistol_reload(entities_t *entities)
{
    add_key(entities, "player", "pistol:reload", v_2f{18.0f, 417.0f});
    add_key(entities, "player", "pistol:reload", v_2f{108.0f, 417.0f});
    add_key(entities, "player", "pistol:reload", v_2f{192.0f, 417.0f});
    add_key(entities, "player", "pistol:reload", v_2f{275.0f, 417.0f});
    add_key(entities, "player", "pistol:reload", v_2f{362.0f, 417.0f});
    add_key(entities, "player", "pistol:reload", v_2f{449.0f, 417.0f});
    add_key(entities, "player", "pistol:reload", v_2f{533.0f, 417.0f});
    add_key(entities, "player", "pistol:reload", v_2f{624.0f, 417.0f});
}

void set_player_key_rifle_reload(entities_t *entities)
{
    add_key(entities, "player", "rifle:reload", v_2f{18.0f, 657.0f});
    add_key(entities, "player", "rifle:reload", v_2f{119.0f, 657.0f});
    add_key(entities, "player", "rifle:reload", v_2f{227.0f, 657.0f});
    add_key(entities, "player", "rifle:reload", v_2f{335.0f, 657.0f});
    add_key(entities, "player", "rifle:reload", v_2f{362.0f, 657.0f});
    add_key(entities, "player", "rifle:reload", v_2f{545.0f, 657.0f});
    add_key(entities, "player", "rifle:reload", v_2f{755.0f, 657.0f});
    add_key(entities, "player", "rifle:reload", v_2f{850.0f, 657.0f});
}