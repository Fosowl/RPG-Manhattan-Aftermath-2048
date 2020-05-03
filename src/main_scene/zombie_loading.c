/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** zombie_loading
*/

#include "starset_engine.h"
#include "warlock.h"
#include "scene.h"
#include "path.h"
#include "game_macro.h"
#include "render.h"

void update_zombie_loading(sfRenderWindow *window, int v, int max_v)
{
    sfVector2u screen_size = sfRenderWindow_getSize(window);
    sfVector2u bar_spot = (sfVector2u){(float)screen_size.x / 3
    , (float)screen_size.y / 2};

    sfRenderWindow_clear(window, sfBlack);
    load_bar(window, bar_spot, ((float)v / (float)max_v) * 100, (sfVector2i)
    {screen_size.x, screen_size.y});
    sfRenderWindow_display(window);
}

static entities_t *random_zombie(entities_t *entities, char *name
, sfSprite *prefab, sfSprite *prefab_2)
{
    if (rand() % 2 == 1)
        entities = starset_entities_add_from_prefab(entities, prefab
        , append("zombie:", name), false);
    else
        entities = starset_entities_add_from_prefab(entities, prefab_2
    , append("zombie:", name), false);
    return (entities);
}

entities_t *create_zombie_scene(entities_t *entities, int zombie
, sfRenderWindow *window)
{
    int x = 0;
    int y = 0;
    char *name = NULL;
    sfVector2f *spawn;
    sfSprite *prefab = starset_create_prefab(ZOMBIE_PATH);
    sfSprite *prefab_2 = starset_create_prefab(ZOMBIE_2_PATH);

    spawn = zombie_spawn_point(zombie);
    for (int i = 0; i < zombie; i++) {
        name = my_itoa(i);
        update_zombie_loading(window, i, zombie);
        random_zombie(entities, name, prefab, prefab_2);
        x = spawn[i].x;
        y = spawn[i].y;
        starset_entities_teleport(entities, name, x, y);
    }
    starset_entities_get_propreties(entities, "zombie:0")->spot.x = -5000000;
    starset_entities_get_propreties(entities, "zombie:0")->visible = false;
    starset_entities_get_propreties(entities, "zombie:0")->speed = 0;
    return (entities);
}

void draw_loading_text(sfRenderWindow *window)
{
    sfText *text_load = NULL;
    sfVector2f spot;
    sfVector2u bar_spot;
    sfVector2u screen_size;

    screen_size = sfRenderWindow_getSize(window);
    spot.x = screen_size.x / 2;
    spot.y = screen_size.y / 2;
    bar_spot.x = screen_size.x / 3;
    bar_spot.y = screen_size.y / 2;
    text_load = load_text("loading...", 15, spot, RED);
    if (!text_load)
        return;
    sfRenderWindow_drawText(window, text_load, NULL);
    load_bar(window, bar_spot, 10, (sfVector2i){screen_size.x, screen_size.y});
    sfRenderWindow_display(window);
}