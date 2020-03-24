/*
** EPITECH PROJECT, 2019
** render.h
** File description:
** function prototype for my graphics lib
*/

#ifndef RENDER_H_
#define RENDER_H_

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Clock.h>

#include <math.h>
#include <stdlib.h>

#define RED (sfColor){220, 20, 0, 200}
#define BLUE (sfColor){0, 40, 220, 200}
#define BLACK (sfColor){0, 0, 0, 200}
#define WHITE (sfColor){255, 255, 255, 200}
#define GREEN (sfColor){20, 240, 5, 200}
#define PURPLE (sfColor){204, 0, 153, 200}
#define ORANGE (sfColor){253, 153, 0, 200}
#define BROWN (sfColor){102, 51, 0, 200}
#define CYAN (sfColor){4, 204, 255, 200}
#define GLASS_RED (sfColor){220, 20, 0, 70}
#define GLASS_BLUE (sfColor){0, 40, 220, 70}
#define GLASS_BLACK (sfColor){0, 0, 0, 70}
#define GLASS_WHITE (sfColor){255, 255, 255, 70}
#define GLASS_GREEN (sfColor){20, 240, 5, 70}
#define GLASS_PURPLE (sfColor){204, 0, 153, 70}
#define GLASS_ORANGE (sfColor){253, 153, 0, 70}
#define GLASS_BROWN (sfColor){102, 51, 0, 70}
#define GLASS_CYAN (sfColor){4, 204, 255, 70}

typedef struct screen_t {
    sfRenderWindow *window;
    sfVector2i size;
    sfVideoMode mode;
} screen_t;

typedef struct myframebuffer {
    sfInt8 *pixels;
    unsigned int width;
    unsigned int height;
} framebuffer_t;

typedef struct sound_t {
    sfSound *sound;
    sfSoundBuffer *buffer;
    sfTime start;
    int volume;
    sfTime end;
    sfTime loop;
} sound_t;

typedef struct object_t {
    sfSprite *sprite;
    sfTexture *texture;
    float rotation;
    float speed;
    int visible;
    int weight;
    sfFloatRect hitbox;
    sfVector2f position;
    sfVector2f goal;
    sfVector2f origin;
} object_t;

typedef struct view_t {
    sfView *view;
    sfVector2f position;
    float zoom;
    sfWindow *sfWindow;
} view_t;

typedef struct button_t {
    int text_size;
    int start_size;
    sfVector2u size;
    sfVector2f position;
    sfTexture *texture;
    sfTexture *texture_box;
    sfSprite *sprite;
    sfSprite *sprite_box;
    sfIntRect rect;
    sfText *text;
} button_t;

int my_strlen(char *str);

// sprite_creator.c

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
object_t *create_object(char *path, float x, float y, float angle);

// drawing.c

int my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y
, sfColor color);

void my_draw_square(framebuffer_t *framebuffer, sfVector2u position,
sfVector2f size, sfColor color);

void my_draw_circle_pit(sfVector2f position, sfColor color
, float radius, sfRenderWindow *window);

// measure_distance.c

float distance(sfVector2f *from, sfVector2f *to);

// move_sprite.c

void move_from_angle(sfVector2f *vector, float angle, float average_speed);
float angle_to_sprite(sfVector2f from, sfVector2f to);
float move_sprite(sfVector2f *from, sfVector2f *to, float average_speed);
void move_sprite_invert_angle(sfVector2f *from, sfVector2f *to
, int *revert_angle, sfVector2f *vector);
    
// physics.c

void simulate_wind(object_t *object, float direction, int force);

// random.c

int real_random(int max, sfClock *clock);

//time.c

void my_sleep(int wait);

// button_classic.c

button_t *create_button(char *path, sfVector2f position, char *text, int s);
void resize_button(int center_left, int center_top, button_t *button);
int button_render_and_check(sfRenderWindow *window, sfEvent *ev
, button_t *button);

// button_simple.c
button_t *create_simple_button(char *path, sfVector2f position, char *text);
int simple_button_render_and_check(sfRenderWindow *window, sfEvent *event
, button_t *button);

// ui.c

void life_bar(sfRenderWindow *window, sfVector2u position, int life
, sfVector2i screen_size);

// text.c

sfText *load_text(char *string, int size, sfVector2f vector, sfColor color);

// loading_bar.c

void loading_bar(sfRenderWindow *window, sfVector2u position
, int life, char *resource);

// screen.c

int outside_screen(sfVector2f position, float x, float y);

// sound_creator.c

sound_t *create_sound(char *file, int loud);

#endif /* !RENDER_H_ */
