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

static void set_each_key(entities_t *player)
{
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
    set_each_key(player);
}