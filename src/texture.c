/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** texture
*/

#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    TextureClass_t *self = (TextureClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
}

void load_textures(TextureClass_t *self)
{
    self->wallTextures = malloc(sizeof(sfTexture*) * NUM_TEXTURES);
    self->wallTextures[0] = sfTexture_createFromFile("assets/textures/str_metalflr1.png", NULL);

    self->wallSprite = sfSprite_create();
    self->textureSize = 64;
}

const TextureClass_t texture_init = { 
    {
        ._size = sizeof texture_init,
        ._name = "TextureClass_t",
        ._constructor = constructor,
    },
    .load_textures = load_textures,
};

const class_t *Texture = (class_t *) &texture_init;
