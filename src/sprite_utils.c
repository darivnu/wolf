/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sprite_utils
*/

#include "game.h"

void set_scale(SpriteClass_t *self, float x, float y)
{
    self->scale.x = x;
    self->scale.y = y;
    sfSprite_setScale(self->sprite, self->scale);
}

void set_rotation(SpriteClass_t *self, float angle)
{
    self->rotation = angle;
    sfSprite_setRotation(self->sprite, self->rotation);
}

void set_visible(SpriteClass_t *self, int visible)
{
    self->visible = visible;
}

void set_animation(SpriteClass_t *self, animation_data_t *animation)
{
    self->current_animation = animation;
    if (animation && animation->frame_count > 0) {
        sfSprite_setTextureRect(self->sprite, 
            animation->frames[animation->current_frame].rect);
    }
}
