/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sound_volume
*/

#include "game.h"

void set_master_volume(SoundClass_t *self, float volume)
{
    int i;
    float actual_volume;

    self->master_volume = volume;
    for (i = 0; i < self->effect_count; i++) {
        if (self->effects[i]->sound) {
            actual_volume = self->effects[i]->volume * self->effect_volume
                * self->master_volume;
            sfSound_setVolume(self->effects[i]->sound, actual_volume * 100.0f);
        }
    }
    for (i = 0; i < self->music_count; i++) {
        if (self->music[i]->music) {
            actual_volume = self->music[i]->volume * self->music_volume
                * self->master_volume;
            sfMusic_setVolume(self->music[i]->music, actual_volume * 100.0f);
        }
    }
}

void set_effect_volume(SoundClass_t *self, float volume)
{
    int i;
    float actual_volume;

    self->effect_volume = volume;
    for (i = 0; i < self->effect_count; i++) {
        if (self->effects[i]->sound) {
            actual_volume = self->effects[i]->volume * self->effect_volume
                * self->master_volume;
            sfSound_setVolume(self->effects[i]->sound, actual_volume * 100.0f);
        }
    }
}

void set_music_volume_global(SoundClass_t *self, float volume)
{
    int i;
    float actual_volume;

    self->music_volume = volume;
    for (i = 0; i < self->music_count; i++) {
        if (self->music[i]->music) {
            actual_volume = self->music[i]->volume * self->music_volume
                * self->master_volume;
            sfMusic_setVolume(self->music[i]->music, actual_volume * 100.0f);
        }
    }
}
