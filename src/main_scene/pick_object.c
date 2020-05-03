/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** pick_object
*/

#include "starset_engine.h"
#include "warlock.h"
#include "scene.h"
#include "path.h"
#include "game_macro.h"
#include "render.h"
#include "inventory.h"

static void propeties_pick_object(entities_t *entities)
{
    entities_t *tmp = NULL;

    while ((tmp = starset_get_next(entities, "pick"))) {
        srand((long long int)tmp % RAND_MAX);
        tmp->is_trigger = true;
        tmp->spot.x = rand() % 1000;
        tmp->spot.y = rand() % 1000;
    }
}

entities_t *load_pick_object(entities_t *entities, int nb)
{
    int r = 0;

    entities = starset_entities_add(entities, PICK_RIFLE_PATH
    , "pick:rifle", true);
    for (int i = 0; i < nb; i++) {
        srand(i * 145);
        r = rand() % 4;
        if (r == 0)
            entities = starset_entities_add(entities, PICK_AMMO_RIFLE_PATH
            , "pick:ammo_rifle", true);
        if (r == 1)
            entities = starset_entities_add(entities, PICK_KIT_PATH,
            "pick:kit", true);
        if (r >= 2)
            entities = starset_entities_add(entities, PICK_AMMO_PISTOL_PATH
            , "pick:ammo_pistol", true);
    }
    propeties_pick_object(entities);
    return (entities);
}

void pick_item(game_t *game)
{
    if (!game->player.save->collision)
        return;
    if (game->player.save->collision->visible == false)
        return;
    if (compare(game->player.save->collision->name, "pick:ammo_rifle")) {
        game->player.nb_magazine_rifle += 1;
        game->inventory->contains[BULLET_AK47].nb += 10;
    }
    if (compare(game->player.save->collision->name, "pick:ammo_pistol")) {
        game->player.nb_magazine_gun += 1;
        game->inventory->contains[BULLET_GUN].nb += 11;
    }
    if (compare(game->player.save->collision->name, "pick:rifle")) {
        game->player.unlock_rifle = true;
        starset_single_play_sound(game->player.save, "yes", false);
        game->player.selected = fill("rifle");
    }
    if (search("pick:", game->player.save->collision->name) != -1)
        game->player.save->collision->visible = false;
}
