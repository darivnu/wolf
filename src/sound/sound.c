/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sound
*/

#include <stdlib.h>
#include <string.h>
#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    SoundClass_t *self = (SoundClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
    self->effects = NULL;
    self->music = NULL;
    self->effect_count = 0;
    self->music_count = 0;
    self->master_volume = 1.0f;
    self->effect_volume = 1.0f;
    self->music_volume = 1.0f;
}

static void destructor(void *ptr)
{
    SoundClass_t *self = (SoundClass_t *) ptr;
    sound_effect_t *effect;
    int i;

    for (i = 0; i < self->effect_count; i++) {
        effect = self->effects[i];
        if (effect->sound)
            sfSound_destroy(effect->sound);
        if (effect->buffer)
            sfSoundBuffer_destroy(effect->buffer);
        if (effect->name)
            free(effect->name);
        free(effect);
    }
    if (self->effects)
        free(self->effects);
    if (self->music)
        free(self->music);
}

const SoundClass_t sound_init = {
    {
        ._size = sizeof sound_init,
        ._name = "SoundClass_t",
        ._constructor = constructor,
        ._destructor = destructor,
    },
    .create_sound_effect = create_sound_effect,
    .create_music = create_music,
    .play_sound = play_sound,
    .play_music = play_music,
    .stop_sound = stop_sound,
    .stop_music = stop_music,
    .pause_sound = pause_sound,
    .pause_music = pause_music,
    .set_sound_volume = set_sound_volume,
    .set_music_volume = set_music_volume,
    .set_master_volume = set_master_volume,
    .set_effect_volume = set_effect_volume,
    .set_music_volume_global = set_music_volume_global,
    .set_sound_3d_position = set_sound_3d_position,
    .update_listener_position = update_listener_position,
    .get_sound = get_sound,
    .get_music = get_music,
    .update_sounds = update_sounds,
    .update_sounds_effect = update_sounds_effect,
    .update_sounds_music = update_sounds_music,
    .cleanup_sounds = cleanup_sounds,
};

const class_t *Sound = (const class_t *) &sound_init;
