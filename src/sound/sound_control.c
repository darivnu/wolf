/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sound_control
*/

#include "../../inc/game.h"

void pause_sound(SoundClass_t *self, const char *name)
{
    sound_effect_t *effect;

    effect = self->get_sound(self, name);
    if (!effect || !effect->sound)
        return;
    sfSound_pause(effect->sound);
}

void pause_music(SoundClass_t *self, const char *name)
{
    sound_music_t *music;

    music = self->get_music(self, name);
    if (!music || !music->music)
        return;
    sfMusic_pause(music->music);
}

void set_sound_volume(SoundClass_t *self, const char *name, float volume)
{
    sound_effect_t *effect;
    float actual_volume;

    effect = self->get_sound(self, name);
    if (!effect || !effect->sound)
        return;
    effect->volume = volume;
    actual_volume = effect->volume * self->effect_volume * self->master_volume;
    sfSound_setVolume(effect->sound, actual_volume * 100.0f);
}

void set_music_volume(SoundClass_t *self, const char *name, float volume)
{
    sound_music_t *music;
    float actual_volume;

    music = self->get_music(self, name);
    if (!music || !music->music)
        return;
    music->volume = volume;
    actual_volume = music->volume * self->music_volume * self->master_volume;
    sfMusic_setVolume(music->music, actual_volume * 100.0f);
}
