/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** map
*/

#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    MapClass_t *self = (MapClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
}

const MapClass_t map_init = {
    {
        ._size = sizeof map_init,
        ._name = "MapClass_t",
        ._constructor = constructor,
    },
};

const class_t *Map = (class_t *) &map_init;
