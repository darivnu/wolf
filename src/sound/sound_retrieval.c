/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sound_retrieval
*/

#include <string.h>
#include "../../inc/game.h"

sound_effect_t *get_sound(SoundClass_t *self, const char *name)
{
    int i;

    for (i = 0; i < self->effect_count; i++) {
        if (strcmp(self->effects[i]->name, name) == 0)
            return self->effects[i];
    }
    return NULL;
}

sound_music_t *get_music(SoundClass_t *self, const char *name)
{
    int i;

    for (i = 0; i < self->music_count; i++) {
        if (strcmp(self->music[i]->name, name) == 0)
            return self->music[i];
    }
    return NULL;
}

void destroy_music(SoundClass_t *self)
{
    sound_music_t *music;
    int i;

    for (i = 0; i < self->music_count; i++) {
        music = self->music[i];
        if (music->music)
            sfMusic_destroy(music->music);
        if (music->name)
            free(music->name);
        free(music);
    }
}
