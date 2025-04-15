/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** game
*/

#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    GameClass_t *self = (GameClass_t *) ptr;

    self->ray = new_class(Ray, self);
    self->player = new_class(Player, self);
    self->map = new_class(Map, self);
}

static void destructor(void *ptr)
{
    GameClass_t *self = (GameClass_t *) ptr;

    destroy_class(self->ray);
    destroy_class(self->player);
    destroy_class(self->map);
}

const GameClass_t game_init = {
    {
        ._size = sizeof game_init,
        ._name = "GameClass_t",
        ._constructor = constructor,
        ._destructor = destructor,
    },
};

const class_t *Game = (const class_t *) &game_init;
