/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** ray
*/

#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    RayClass_t *self = (RayClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
}

const RayClass_t ray_init = {
    {
        ._size = sizeof ray_init,
        ._name = "RayClass_t",
        ._constructor = constructor,
    },
};

const class_t *Ray = (const class_t *) &ray_init;
