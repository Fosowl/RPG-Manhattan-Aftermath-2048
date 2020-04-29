/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** ui
*/

#include "game_struct.h"
#include "scene.h"
#include "render.h"
#include "warlock.h"
#include "game_macro.h"

static void show_ammo_ui(ui_ammo_t *a, game_t *game, sfText **text_ui)
{
    if (!text_ui[TOTAL] || !text_ui[MAG]) {
        text_ui[TOTAL] = load_text(a->str_total, 40, a->p_ui[TOTAL], WHITE);
        text_ui[MAG] = load_text(a->str_mag, 40, a->p_ui[MAG], WHITE);
    }
    sfText_setString(text_ui[MAG], a->str_mag);
    sfText_setString(text_ui[TOTAL], a->str_total);
    sfRenderWindow_drawText(game->window, text_ui[MAG], NULL);
    sfRenderWindow_drawText(game->window, text_ui[TOTAL], NULL);
    free(a->str_mag);
    free(a->str_total);
}

static void ammo_ui(game_t *game)
{
    static sfText *text_ui[2];
    ui_ammo_t a;

    a.s = sfRenderWindow_getSize(game->window);
    a.p_ui[MAG] = (sfVector2f){a.s.x - (a.s.x / 6), a.s.y - (a.s.y / 5)};
    a.p_ui[TOTAL] = (sfVector2f){a.s.x - (a.s.x / 6), a.s.y - (a.s.y / 5) + 50};
    if (compare(game->player.selected, "rifle")) {
        a.str_mag = append("magazine : ", my_itoa(game->player.ammo_rifle));
        a.str_total = append("total : "
        , my_itoa(game->player.nb_magazine_rifle));
    } else if (compare(game->player.selected, "pistol")) {
        a.str_mag = append("magazine : ", my_itoa(game->player.ammo_gun));
        a.str_total = append("total : ", my_itoa(game->player.nb_magazine_gun));
    } else
        return;
    show_ammo_ui(&a, game, &text_ui);
}

static void reload_ui(sfRenderWindow *window)
{
    static sfText *text_ui;
    sfVector2u screen_size = sfRenderWindow_getSize(window);
    sfVector2f spot;

    spot.x = screen_size.x / 2;
    spot.y = screen_size.y / 2;
    if (!text_ui) {
        text_ui = load_text("reload", 70, spot, WHITE);
    }
    sfRenderWindow_drawText(window, text_ui, NULL);
}

static void critical_ui(sfRenderWindow *window)
{
    static sfText *text_ui;
    sfVector2u screen_size = sfRenderWindow_getSize(window);
    sfVector2f spot;

    spot.x = screen_size.x / 2;
    spot.y = screen_size.y / 2;
    if (!text_ui) {
        text_ui = load_text("C R I T I C A L   L I F E", 70, spot, RED);
    }
    sfRenderWindow_drawText(window, text_ui, NULL);
}

void update_ui(game_t *game)
{
    ammo_ui(game);
    if (compare(game->player.selected, "rifle") &&
    game->player.ammo_rifle <= 0)
        reload_ui(game->window);
    else if (compare(game->player.selected, "pistol") &&
    game->player.ammo_gun <= 0)
        reload_ui(game->window);
    else if (game->player.save->life <= 25)
        critical_ui(game->window);
}