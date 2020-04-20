/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** set_player_anim
*/

#include "starset_engine.h"
#include "scene.h"
#include "game_macro.h"

//
// animation for each weapon (pistol, knife, rifle, torch)
// - static (not moving) 
// - move (moving)
// - attack (exept for torch)
// - reload (only for pistol and rifle)
// only animation is tatic for torch
//

void set_player_animation(entities_t *entities)
{
    entities_t *player = starset_entities_get_propreties(entities, "player");

    starset_add_animation(player, "player", "torch:static", v_2u{95, 80});
    starset_add_animation(player, "player", "pistol:static", v_2u{95, 80});
    starset_add_animation(player, "player", "pistol:move", v_2u{95, 80});
    starset_add_animation(player, "player", "pistol:attack", v_2u{95, 80});
    starset_add_animation(player, "player", "pistol:reload", v_2u{95, 80});
    starset_add_animation(player, "player", "rifle:static", v_2u{95, 80});
    starset_add_animation(player, "player", "rifle:move", v_2u{95, 80});
    starset_add_animation(player, "player", "rifle:attack", v_2u{98, 80});
    starset_add_animation(player, "player", "rifle:reload", v_2u{95, 80});
    starset_add_animation(player, "player", "knife:static", v_2u{95, 80});
    starset_add_animation(player, "player", "knife:move", v_2u{95, 80});
    starset_add_animation(player, "player", "knife:attack", v_2u{95, 95});
    set_player_key_torch_static(player);
    set_player_key_pistol_static(player);
    set_player_key_rifle_static(player);
    set_player_key_knife_static(player);
    set_player_key_pistol_move(player);
    set_player_key_rifle_move(player);
    set_player_key_knife_move(player);
    set_player_key_pistol_attack(player);
    set_player_key_rifle_attack(player);
    set_player_key_knife_attack(player);
    set_player_key_pistol_reload(player);
    set_player_key_rifle_reload(player);
}

void set_player_key_torch_static(entities_t *player)
{
    add_key(player, "player", "torch:static", v_2f{17.0f, 0.0f});
    add_key(player, "player", "torch:static", v_2f{116.0f, 0.0f});
    add_key(player, "player", "torch:static", v_2f{420.0f, 0.0f});
    add_key(player, "player", "torch:static", v_2f{519.0f, 0.0f});
    add_key(player, "player", "torch:static", v_2f{620.0f, 0.0f});
    add_key(player, "player", "torch:static", v_2f{825.0f, 0.0f});
    add_key(player, "player", "torch:static", v_2f{923.0f, 0.0f});
}

void set_player_key_pistol_static(entities_t *player)
{
    add_key(player, "player", "pistol:static", v_2f{17.0f, 350.0f});
    add_key(player, "player", "pistol:static", v_2f{99.0f, 350.0f});
    add_key(player, "player", "pistol:static", v_2f{180.0f, 350.0f});
    add_key(player, "player", "pistol:static", v_2f{264.0f, 350.0f});
    add_key(player, "player", "pistol:static", v_2f{348.0f, 350.0f});
    add_key(player, "player", "pistol:static", v_2f{432.0f, 350.0f});
    add_key(player, "player", "pistol:static", v_2f{515.0f, 350.0f});
    add_key(player, "player", "pistol:static", v_2f{600.0f, 350.0f});
    add_key(player, "player", "pistol:static", v_2f{686.0f, 350.0f});
    add_key(player, "player", "pistol:static", v_2f{764.0f, 350.0f});
}

void set_player_key_rifle_static(entities_t *player)
{
    add_key(player, "player", "rifle:static", v_2f{6.0f, 580.0f});
    add_key(player, "player", "rifle:static", v_2f{102.0f, 580.0f});
    add_key(player, "player", "rifle:static", v_2f{212.0f, 580.0f});
    add_key(player, "player", "rifle:static", v_2f{734.0f, 580.0f});
    add_key(player, "player", "rifle:static", v_2f{833.0f, 580.0f});
    add_key(player, "player", "rifle:static", v_2f{935.0f, 580.0f});
}

void set_player_key_knife_static(entities_t *player)
{
    add_key(player, "player", "knife:static", v_2f{10.0f, 87.0f});
    add_key(player, "player", "knife:static", v_2f{112.0f, 87.0f});
    add_key(player, "player", "knife:static", v_2f{210.0f, 87.0f});
    add_key(player, "player", "knife:static", v_2f{290.0f, 87.0f});
    add_key(player, "player", "knife:static", v_2f{390.0f, 87.0f});
    add_key(player, "player", "knife:static", v_2f{485.0f, 87.0f});
    add_key(player, "player", "knife:static", v_2f{585.0f, 87.0f});
    add_key(player, "player", "knife:static", v_2f{685.0f, 87.0f});
    add_key(player, "player", "knife:static", v_2f{785.0f, 87.0f});
    add_key(player, "player", "knife:static", v_2f{885.0f, 87.0f});
}