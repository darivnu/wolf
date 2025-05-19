/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sprite_render
*/

#include "game.h"

void update_sprite(SpriteClass_t *self, float delta_time)
{
    if (!self->current_animation || !self->current_animation->is_playing)
        return;

    sfSprite_setTextureRect(self->sprite, 
        self->current_animation->frames[
            self->current_animation->current_frame].rect);
}

void draw_sprite(SpriteClass_t *self)
{
    if (!self->visible)
        return;

    sfRenderWindow_drawSprite(
        self->parent->render->window, self->sprite, NULL);
}