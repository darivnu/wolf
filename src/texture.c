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

const TextureClass_t texture_init = { 
    {
        ._size = sizeof texture_init,
        ._name = "TextureClass_t",
        ._constructor = constructor,
    },
};

const class_t *Texture = (class_t *) &texture_init;
