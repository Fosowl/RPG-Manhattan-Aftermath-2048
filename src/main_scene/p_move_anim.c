/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** player move animation
*/

#include "starset_engine.h"
#include "scene.h"
#include "game_macro.h"

void set_player_key_pistol_move(entities_t *entities)
{
    add_key(entities, "player", "pistol:move", v_2f{17.0f, 350.0f});
    add_key(entities, "player", "pistol:move", v_2f{99.0f, 350.0f});
    add_key(entities, "player", "pistol:move", v_2f{180.0f, 350.0f});
    add_key(entities, "player", "pistol:move", v_2f{264.0f, 350.0f});
    add_key(entities, "player", "pistol:move", v_2f{348.0f, 350.0f});
    add_key(entities, "player", "pistol:move", v_2f{432.0f, 350.0f});
    add_key(entities, "player", "pistol:move", v_2f{515.0f, 350.0f});
    add_key(entities, "player", "pistol:move", v_2f{600.0f, 350.0f});
    add_key(entities, "player", "pistol:move", v_2f{686.0f, 350.0f});
    add_key(entities, "player", "pistol:move", v_2f{764.0f, 350.0f});
}

void set_player_key_rifle_move(entities_t *entities)
{
    add_key(entities, "player", "rifle:move", v_2f{6.0f, 580.0f});
    add_key(entities, "player", "rifle:move", v_2f{102.0f, 580.0f});
    add_key(entities, "player", "rifle:move", v_2f{212.0f, 580.0f});
    add_key(entities, "player", "rifle:move", v_2f{318.0f, 580.0f});
    add_key(entities, "player", "rifle:move", v_2f{422.0f, 580.0f});
    add_key(entities, "player", "rifle:move", v_2f{518.0f, 580.0f});
    add_key(entities, "player", "rifle:move", v_2f{623.0f, 580.0f});
    add_key(entities, "player", "rifle:move", v_2f{734.0f, 580.0f});
    add_key(entities, "player", "rifle:move", v_2f{833.0f, 580.0f});
    add_key(entities, "player", "rifle:move", v_2f{935.0f, 580.0f});
}

void set_player_key_knife_move(entities_t *entities)
{
    add_key(entities, "player", "knife:move", v_2f{10.0f, 87.0f});
    add_key(entities, "player", "knife:move", v_2f{112.0f, 87.0f});
    add_key(entities, "player", "knife:move", v_2f{210.0f, 87.0f});
    add_key(entities, "player", "knife:move", v_2f{290.0f, 87.0f});
    add_key(entities, "player", "knife:move", v_2f{390.0f, 87.0f});
    add_key(entities, "player", "knife:move", v_2f{485.0f, 87.0f});
    add_key(entities, "player", "knife:move", v_2f{585.0f, 87.0f});
    add_key(entities, "player", "knife:move", v_2f{685.0f, 87.0f});
    add_key(entities, "player", "knife:move", v_2f{785.0f, 87.0f});
    add_key(entities, "player", "knife:move", v_2f{885.0f, 87.0f});
}