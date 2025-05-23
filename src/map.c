/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** map
*/

#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    MapClass_t *self = (MapClass_t *)ptr;

    self->parent = va_arg(*args, GameClass_t *);
    self->width = 0;
    self->height = 0;
    self->data = NULL;
}

static void destructor(void *ptr)
{
    MapClass_t *self = (MapClass_t *)ptr;

    self->map_cleanup(self);
}

void map_cleanup(MapClass_t *self)
{
    int y;

    if (!self->data)
        return;
    for (y = 0; y < self->height; y++) {
        if (self->data[y])
            free(self->data[y]);
    }
    free(self->data);
    self->data = NULL;
    self->width = 0;
    self->height = 0;
}

int parse_map_header(FILE *file, int *width, int *height)
{
    if (fscanf(file, "%d %d", width, height) != 2)
        return 84;
    if (*width <= 0 || *height <= 0)
        return 84;
    if (*width > 1000 || *height > 1000)
        return 84;
    return 0;
}

int allocate_map_data(MapClass_t *self)
{
    int y;

    self->data = malloc(self->height * sizeof(int *));
    if (!self->data)
        return 84;
    for (y = 0; y < self->height; y++) {
        self->data[y] = malloc(self->width * sizeof(int));
        if (!self->data[y]) {
            self->map_cleanup(self);
            return 84;
        }
    }
    return 0;
}

int map_get_cell(MapClass_t *self, int x, int y)
{
    if (x < 0 || x >= self->width || y < 0 || y >= self->height) {
        return 1;
    }
    return self->data[y][x];
}

const MapClass_t map_init = {
    {
        ._size = sizeof map_init,
        ._name = "MapClass_t",
        ._constructor = constructor,
        ._destructor = destructor,
    },
    .map_get_cell = map_get_cell,
    .map_load_from_file = map_load_from_file,
    .map_cleanup = map_cleanup,
    .parse_map_header = parse_map_header,
    .allocate_map_data = allocate_map_data,
    .load_map_data = load_map_data,
    .load_map_row = load_map_row,
    .open_map_file = open_map_file,
    .process_map_file = process_map_file,
};

const class_t *Map = (class_t *)&map_init;
