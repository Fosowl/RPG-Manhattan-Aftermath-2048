/*
** EPITECH PROJECT, 2020
** PROJECT-011
** File description:
** load_entities into scene
*/

#include "starset_engine.h"
#include "warlock.h"
#include "scene.h"
#include "path.h"
#include "game_macro.h"
#include "render.h"

static void update_zombie_loading(sfRenderWindow *window, int v, int max_v)
{
    sfVector2u screen_size = sfRenderWindow_getSize(window);
    sfVector2u bar_position = (sfVector2u){(float)screen_size.x / 3
    , (float)screen_size.y / 2};

    sfRenderWindow_clear(window, sfBlack);
    load_bar(window, bar_position, ((float)v / (float)max_v) * 100, (sfVector2i)
    {screen_size.x, screen_size.y});
    sfRenderWindow_display(window);
}

static entities_t *create_zombie_scene(entities_t *entities, int zombie
, sfRenderWindow *window)
{
    int x = 0;
    int y = 0;
    char *name = NULL;
    entities_t *tmp = NULL;
    sfVector2f *spawn;
    sfSprite *prefab = starset_create_prefab(ZOMBIE_PATH);

    spawn = zombie_spawn_point(zombie);
    for (int i = 0; i < zombie; i++) {
        name = my_itoa(i);
        update_zombie_loading(window, i, zombie);
        entities = starset_entities_add_from_prefab(entities, prefab
        , append("zombie:", name), false);
        tmp = starset_entities_get_propreties(entities, name);
        x = spawn[i].x;
        y = spawn[i].y;
        starset_entities_teleport(entities, name, x, y);
        usleep(10000);
    }
    return (entities);
}

static void draw_loading_text(sfRenderWindow *window)
{
    sfText *text_load = NULL;
    sfVector2f position;
    sfVector2u bar_position;
    sfVector2u screen_size;

    screen_size = sfRenderWindow_getSize(window);
    position.x = screen_size.x / 2;
    position.y = screen_size.y / 2;
    bar_position.x = screen_size.x / 3;
    bar_position.y = screen_size.y / 2;
    text_load = load_text("loading...", 15, position, RED);
    if (!text_load)
        return;
    sfRenderWindow_drawText(window, text_load, NULL);
    load_bar(window, bar_position, 10, (sfVector2i){screen_size.x, screen_size.y});
    sfRenderWindow_display(window);
}

static void set_player_propreties(entities_t *entities)
{
    starset_entities_teleport(entities, "player", 400, 900);
    starset_entities_get_propreties(entities, "player")->speed = 3;
    starset_entities_get_propreties(entities, "bullet")->is_trigger = true;
    starset_entities_get_propreties(entities, "bullet")->speed = 9;
    starset_entities_get_propreties(entities, "bullet")->visible = false;
    starset_entities_get_propreties(entities
    , "bullet")->position = (sfVector2f){ -100.0f, -100.0f};
}

entities_t *load_entities_scene(int zombie, sfRenderWindow *window)
{
    entities_t *entities = NULL;

    sfRenderWindow_clear(window, sfBlack);
    draw_loading_text(window);
    //entities = starset_entities_add(entities, DOG_PATH, "dog", false);
    entities = create_zombie_scene(entities, zombie, window);
    entities = starset_entities_add(entities, PLAYER_PATH, "player", false);
    entities = starset_entities_add(entities, BULLET_PATH, "bullet", false);
    if (!entities)
        return (NULL);
    //set_dog(entities);
    set_zombie_animation(entities);
    set_zombie_sound(entities, zombie);
    set_player_animation(entities);
    set_player_sound(entities);
    set_player_propreties(entities);
    return (entities);
}