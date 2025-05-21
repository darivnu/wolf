/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sound_creation
*/

#include <stdlib.h>
#include <string.h>
#include "game.h"


void init_music(sound_music_t *music, const char *name)
{
    music->name = strdup(name);
    music->music = NULL;
    music->volume = 1.0f;
    music->mode = SOUND_LOOP;
    music->is_playing = 0;
}

sound_effect_t *allocate_effect_memory(SoundClass_t *self, const char *name)
{
    sound_effect_t *effect;
    void *temp;

    temp = realloc(self->effects,
        (self->effect_count + 1) * sizeof(sound_effect_t *));
    if (!temp)
        return NULL;
    self->effects = temp;
    effect = malloc(sizeof(sound_effect_t));
    if (!effect)
        return NULL;
    init_sound_effect(effect, name);
    return effect;
}

int setup_sound_buffer(sound_effect_t *effect, const char *filepath)
{
    effect->buffer = sfSoundBuffer_createFromFile(filepath);
    if (!effect->buffer)
        return 0;
    effect->sound = sfSound_create();
    if (!effect->sound) {
        sfSoundBuffer_destroy(effect->buffer);
        effect->buffer = NULL;
        return 0;
    }
    sfSound_setBuffer(effect->sound, effect->buffer);
    return 1;
}

sound_effect_t *create_sound_effect(SoundClass_t *self, const char *name,
    const char *filepath)
{
    sound_effect_t *effect;

    effect = allocate_effect_memory(self, name);
    if (!effect)
        return NULL;
    if (!setup_sound_buffer(effect, filepath)) {
        free(effect);
        return NULL;
    }
    self->effects[self->effect_count] = effect;
    self->effect_count++;
    return effect;
}

sound_music_t *create_music(SoundClass_t *self, const char *name,
    const char *filepath)
{
    sound_music_t *music;
    void *temp;

    temp = realloc(self->music,
        (self->music_count + 1) * sizeof(sound_music_t *));
    if (!temp)
        return NULL;
    self->music = temp;
    music = malloc(sizeof(sound_music_t));
    if (!music)
        return NULL;
    init_music(music, name);
    music->music = sfMusic_createFromFile(filepath);
    if (!music->music) {
        free(music);
        return NULL;
    }
    self->music[self->music_count] = music;
    self->music_count++;
    return music;
}
