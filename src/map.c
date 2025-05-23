/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** map
*/

#include "../inc/game.h"

static void constructor(void *ptr, va_list *args)
{
    MapClass_t *self = (MapClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
}

// Temp map creation tool for testing
void map_create(MapClass_t *map, int width, int height)
{
    map->width = width;
    map->height = height;

    map->data = malloc(height * sizeof(int *));
    for (int y = 0; y < height; y++) {
        map->data[y] = malloc(width * sizeof(int));
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
                map->data[y][x] = WALL;
            else
                map->data[y][x] = NOWALL;
        }
    }
    map->data[0][0] = WALL;
    map->data[0][1] = WALL;
    map->data[0][2] = WALL;
    map->data[0][3] = WALL;
    map->data[5][5] = 3;
    map->data[5][6] = 3;
    map->data[5][7] = 2;
    
    // Print the map to stdout
    printf("Map (%d x %d):\n", width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", map->data[y][x]);
        }
        printf("\n");
    }
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
    },
    .map_create = map_create,
    .map_get_cell = map_get_cell,
};

const class_t *Map = (class_t *) &map_init;
