/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** player
*/

#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    PlayerClass_t *self = (PlayerClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
}

const PlayerClass_t player_init = {
    {
        ._size = sizeof player_init,
        ._name = "PlayerClass_t",
        ._constructor = constructor,
    },
};

const class_t *Player = (class_t *) &player_init;
