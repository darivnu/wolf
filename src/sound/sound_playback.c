/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sound_playback
*/

#include "game.h"

void play_sound(SoundClass_t *self, const char *name)
{
    sound_effect_t *effect;
    float actual_volume;

    effect = self->get_sound(self, name);
    if (!effect || !effect->sound) {
        printf("Sound not found or invalid: %s\n", name);
        return;
    }
    actual_volume = effect->volume * self->effect_volume * self->master_volume;
    sfSound_setVolume(effect->sound, actual_volume * 100.0f);
    sfSound_setPitch(effect->sound, effect->pitch);
    if (effect->mode == SOUND_LOOP)
        sfSound_setLoop(effect->sound, sfTrue);
    else
        sfSound_setLoop(effect->sound, sfFalse);
    sfSound_stop(effect->sound);
    sfSound_play(effect->sound);
    effect->is_playing = 1;
}

void play_music(SoundClass_t *self, const char *name)
{
    sound_music_t *music;
    float actual_volume;

    music = self->get_music(self, name);
    if (!music || !music->music)
        return;
    actual_volume = music->volume * self->music_volume * self->master_volume;
    sfMusic_setVolume(music->music, actual_volume * 100.0f);
    if (music->mode == SOUND_LOOP)
        sfMusic_setLoop(music->music, sfTrue);
    else
        sfMusic_setLoop(music->music, sfFalse);
    sfMusic_play(music->music);
    music->is_playing = 1;
}

void stop_sound(SoundClass_t *self, const char *name)
{
    sound_effect_t *effect;

    effect = self->get_sound(self, name);
    if (!effect || !effect->sound)
        return;
    sfSound_stop(effect->sound);
    effect->is_playing = 0;
}

void stop_music(SoundClass_t *self, const char *name)
{
    sound_music_t *music;

    music = self->get_music(self, name);
    if (!music || !music->music)
        return;
    sfMusic_stop(music->music);
    music->is_playing = 0;
}
