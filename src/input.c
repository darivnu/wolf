/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** input
*/

#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    InputClass_t *self = (InputClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
}

const InputClass_t input_init = {
    {
        ._size = sizeof input_init,
        ._name = "InputClass_t",
        ._constructor = constructor,
    },
};

const class_t *Input = (class_t *) &input_init;
