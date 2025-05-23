/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** animation_control
*/

#include <string.h>
#include "../../inc/game.h"

animation_data_t *get_animation(AnimationClass_t *self, const char *name)
{
    int i;

    for (i = 0; i < self->animation_count; i++) {
        if (strcmp(self->animations[i]->name, name) == 0)
            return self->animations[i];
    }
    return NULL;
}

void play_animation(AnimationClass_t *self, const char *name)
{
    animation_data_t *anim;

    anim = get_animation(self, name);
    if (anim) {
        anim->is_playing = 1;
    }
}

void stop_animation(AnimationClass_t *self, const char *name)
{
    animation_data_t *anim;

    anim = get_animation(self, name);
    if (anim) {
        anim->is_playing = 0;
    }
}

void reset_animation(AnimationClass_t *self, const char *name)
{
    animation_data_t *anim;

    anim = get_animation(self, name);
    if (anim) {
        anim->current_frame = 0;
        anim->current_time = 0.0f;
        anim->direction = 1;
    }
}
