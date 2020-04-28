/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** set_girl
*/

#include "starset_engine.h"
#include "warlock.h"
#include "scene.h"
#include "path.h"
#include "game_macro.h"
#include "render.h"

static void set_girl_key_pistol_move(entities_t *girl)
{
    add_key(girl, "sora", "pistol:move", v_2f{17.0f, 350.0f});
    add_key(girl, "sora", "pistol:move", v_2f{99.0f, 350.0f});
    add_key(girl, "sora", "pistol:move", v_2f{180.0f, 350.0f});
    add_key(girl, "sora", "pistol:move", v_2f{264.0f, 350.0f});
    add_key(girl, "sora", "pistol:move", v_2f{348.0f, 350.0f});
    add_key(girl, "sora", "pistol:move", v_2f{432.0f, 350.0f});
    add_key(girl, "sora", "pistol:move", v_2f{515.0f, 350.0f});
    add_key(girl, "sora", "pistol:move", v_2f{600.0f, 350.0f});
    add_key(girl, "sora", "pistol:move", v_2f{686.0f, 350.0f});
    add_key(girl, "sora", "pistol:move", v_2f{764.0f, 350.0f});
}

static void set_girl_key_pistol_static(entities_t *girl)
{
    add_key(girl, "sora", "pistol:static", v_2f{17.0f, 350.0f});
    add_key(girl, "sora", "pistol:static", v_2f{99.0f, 350.0f});
    add_key(girl, "sora", "pistol:static", v_2f{180.0f, 350.0f});
    add_key(girl, "sora", "pistol:static", v_2f{264.0f, 350.0f});
    add_key(girl, "sora", "pistol:static", v_2f{348.0f, 350.0f});
    add_key(girl, "sora", "pistol:static", v_2f{432.0f, 350.0f});
    add_key(girl, "sora", "pistol:static", v_2f{515.0f, 350.0f});
    add_key(girl, "sora", "pistol:static", v_2f{600.0f, 350.0f});
    add_key(girl, "sora", "pistol:static", v_2f{686.0f, 350.0f});
    add_key(girl, "sora", "pistol:static", v_2f{764.0f, 350.0f});
}

void set_girl_animation(entities_t *entities)
{
    entities_t *girl = starset_entities_get_propreties(entities, "sora");

    starset_add_animation(girl, "sora", "pistol:static", v_2u{95, 80});
    starset_add_animation(girl, "sora", "pistol:move", v_2u{95, 80});
    starset_add_animation(girl, "sora", "pistol:attack", v_2u{95, 80});
    set_girl_key_pistol_static(girl);
    set_girl_key_pistol_move(girl);
}