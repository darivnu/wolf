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

void get_input(InputClass_t *self)
{
    if (sfKeyboard_isKeyPressed(sfKeyW))
            self->forward = 1.0;
        if (sfKeyboard_isKeyPressed(sfKeyS))
            self->forward = -1.0;
        if (sfKeyboard_isKeyPressed(sfKeyA))
            self->strafe = -1.0;
        if (sfKeyboard_isKeyPressed(sfKeyD))
            self->strafe = 1.0;
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            self->rotate = -1.0;
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            self->rotate = 1.0;
}

const InputClass_t input_init = {
    {
        ._size = sizeof input_init,
        ._name = "InputClass_t",
        ._constructor = constructor,
    },
    .get_input = get_input,
};

const class_t *Input = (class_t *) &input_init;
