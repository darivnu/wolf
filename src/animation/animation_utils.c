/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** animation_utils
*/

#include <stdlib.h>
#include <string.h>
#include "game.h"

void init_animation_data(
    animation_data_t *anim, const char *name, animation_type_t type)
{
    anim->name = strdup(name);
    anim->type = type;
    anim->frame_count = 0;
    anim->frames = NULL;
    anim->total_duration = 0.0f;
    anim->is_playing = 0;
    anim->current_time = 0.0f;
    anim->current_frame = 0;
    anim->direction = 1;
}

void update_animations(AnimationClass_t *self, float delta_time)
{
    int i;

    for (i = 0; i < self->animation_count; i++) {
        if (self->animations[i]->is_playing) {
            update_animation(self->animations[i], delta_time);
        }
    }
}

void update_animation(animation_data_t *anim, float delta_time)
{
    anim->current_time += delta_time;
    while (anim->current_time >= anim->frames[anim->current_frame].duration) {
        anim->current_time -= anim->frames[anim->current_frame].duration;
        advance_animation_frame(anim);
    }
}

void advance_animation_frame(animation_data_t *anim)
{
    if (anim->type == ANIM_LOOP) {
        anim->current_frame = (anim->current_frame + 1) % anim->frame_count;
    }
    if (anim->type == ANIM_ONCE) {
        if (anim->current_frame < anim->frame_count - 1) {
            anim->current_frame++;
        } else {
            anim->is_playing = 0;
        }
    }
    if (anim->type == ANIM_PINGPONG) {
        handle_pingpong_animation(anim);
    }
}

void handle_pingpong_animation(animation_data_t *anim)
{
    anim->current_frame += anim->direction;
    if (anim->current_frame >= anim->frame_count - 1) {
        anim->current_frame = anim->frame_count - 1;
        anim->direction = -1;
    } else if (anim->current_frame <= 0) {
        anim->current_frame = 0;
        anim->direction = 1;
    }
}
