/*
** EPITECH PROJECT, 2020
** artist_lib
** File description:
** sound
*/

#include "../include/render.h"

sfSound *create_sound_from(char *path)
{
    sfSoundBuffer *buffer = NULL;
    sfSound *sound = sfSound_create();

    if (!sound)
        return (NULL);
    buffer = sfSoundBuffer_createFromFile(path);
    if (!buffer) {
        return (NULL);
    }
    sfSound_setBuffer(sound, buffer);
    return (sound);
}

sound_t *create_sound(char *file, int loud)
{
    sound_t *audio = malloc(sizeof(sound_t));

    audio->buffer = sfSoundBuffer_createFromFile(file);
    audio->sound = sfSound_create();
    sfSound_setBuffer(audio->sound, audio->buffer);
    audio->volume = loud;
    sfSound_setVolume(audio->sound, audio->volume);
    return (audio);
}

void play_sound(struct sound_t *sound, float volume, int loop)
{
    sfSound_play(sound->sound);
    sfSound_setVolume(sound->sound, volume);
    sfSound_setLoop(sound->sound, loop);
}