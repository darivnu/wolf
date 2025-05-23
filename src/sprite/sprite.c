/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sprite
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "../../inc/game.h"

static void constructor(void *ptr, va_list *args)
{
    SpriteClass_t *self = (SpriteClass_t *)ptr;

    self->parent = va_arg(*args, GameClass_t *);
    self->sprite = sfSprite_create();
    self->texture = NULL;
    self->current_animation = NULL;
    self->position = (sfVector2f){0, 0};
    self->scale = (sfVector2f){1, 1};
    self->rotation = 0;
    self->visible = 1;
}

static void destructor(void *ptr)
{
    SpriteClass_t *self = (SpriteClass_t *)ptr;

    if (self->sprite)
        sfSprite_destroy(self->sprite);
    if (self->texture)
        sfTexture_destroy(self->texture);
}

void load_texture(SpriteClass_t *self, const char *filepath)
{
    if (self->texture)
        sfTexture_destroy(self->texture);
    self->texture = sfTexture_createFromFile(filepath, NULL);
    if (self->texture)
        sfSprite_setTexture(self->sprite, self->texture, sfTrue);
}

void set_position(SpriteClass_t *self, float x, float y)
{
    self->position.x = x;
    self->position.y = y;
    sfSprite_setPosition(self->sprite, self->position);
}

const SpriteClass_t sprite_init = {
    {
        ._size = sizeof sprite_init,
        ._name = "SpriteClass_t",
        ._constructor = constructor,
        ._destructor = destructor,
    },
    .load_texture = load_texture,
    .set_position = set_position,
    .set_scale = set_scale,
    .set_rotation = set_rotation,
    .set_visible = set_visible,
    .set_animation = set_animation,
    .update_sprite = update_sprite,
    .draw_sprite = draw_sprite,
};

const class_t *Sprite = (const class_t *)&sprite_init;
