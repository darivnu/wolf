/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sound_update
*/

#include "game.h"

void update_sounds_effect(SoundClass_t *self, int i, sfSoundStatus status)
{
    if (self->effects[i]->sound && self->effects[i]->is_playing) {
            status = sfSound_getStatus(self->effects[i]->sound);
            if (status != sfPlaying)
                self->effects[i]->is_playing = 0;
        }
}

void update_sounds_music(SoundClass_t *self, int i, sfSoundStatus status)
{
    if (self->music[i]->music && self->music[i]->is_playing) {
            status = sfMusic_getStatus(self->music[i]->music);
            if (status != sfPlaying)
                self->music[i]->is_playing = 0;
        }
}

void update_sounds(SoundClass_t *self)
{
    int i;
    sfSoundStatus status = 0;

    for (i = 0; i < self->effect_count; i++) {
        self->update_sounds_effect(self, i, status);
    }
    for (i = 0; i < self->music_count; i++) {
        self->update_sounds_music(self, i, status);
    }
}

void cleanup_sounds(SoundClass_t *self)
{
    int i;

    for (i = 0; i < self->effect_count; i++) {
        if (self->effects[i]->sound)
            sfSound_stop(self->effects[i]->sound);
    }
    for (i = 0; i < self->music_count; i++) {
        if (self->music[i]->music)
            sfMusic_stop(self->music[i]->music);
    }
}
