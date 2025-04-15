/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** render
*/

#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    RenderClass_t *self = (RenderClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
}

const RenderClass_t render_init = {
    {
        ._size = sizeof render_init,
        ._name = "RenderClass_t",
        ._constructor = constructor,
    },
};

const class_t *Render = (class_t *) &render_init;
