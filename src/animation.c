/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** animation
*/

#include <stdlib.h>
#include <string.h>
#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    AnimationClass_t *self = (AnimationClass_t *)ptr;

    self->parent = va_arg(*args, GameClass_t *);
    self->animations = NULL;
    self->animation_count = 0;
}

static void destructor(void *ptr)
{
    AnimationClass_t *self = (AnimationClass_t *)ptr;
    animation_data_t *anim;
    int i;

    for (i = 0; i < self->animation_count; i++) {
        anim = self->animations[i];
        if (anim->frames)
            free(anim->frames);
        if (anim->name)
            free(anim->name);
        free(anim);
    }
    if (self->animations)
        free(self->animations);
}

animation_data_t *create_animation(AnimationClass_t *self, const char *name,
    animation_type_t type)
{
    animation_data_t *anim;
    void *temp;

    temp = realloc(self->animations, 
        (self->animation_count + 1) * sizeof(animation_data_t *));
    if (!temp)
        return NULL;
    self->animations = temp;
    anim = malloc(sizeof(animation_data_t));
    if (!anim)
        return NULL;
    init_animation_data(anim, name, type);
    self->animations[self->animation_count] = anim;
    self->animation_count++;
    return anim;
}

void add_frame(AnimationClass_t *self, animation_data_t *anim, float duration,
    sfIntRect rect)
{
    void *temp;

    temp = realloc(anim->frames, 
        (anim->frame_count + 1) * sizeof(animation_frame_t));
    if (!temp)
        return;
    anim->frames = temp;
    anim->frames[anim->frame_count].duration = duration;
    anim->frames[anim->frame_count].rect = rect;
    anim->total_duration += duration;
    anim->frame_count++;
}

const AnimationClass_t animation_init = {
    {
        ._size = sizeof animation_init,
        ._name = "AnimationClass_t",
        ._constructor = constructor,
        ._destructor = destructor,
    },
    .create_animation = create_animation,
    .add_frame = add_frame,
    .update_animations = update_animations,
    .play_animation = play_animation,
    .stop_animation = stop_animation,
    .reset_animation = reset_animation,
    .get_animation = get_animation,
};

const class_t *Animation = (const class_t *)&animation_init;