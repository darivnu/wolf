/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** load_map
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../inc/map.h"

static int get_height(const char *filepath)
{
    int height = 0;
    int fd = open(filepath, O_RDONLY);
    char c;
    while (read(fd, &c, 1) > 0)
        if (c == '\n')
            height++;
    close(fd);
    return height;
}

static int get_width(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char c;
    int width = 0;

    while (read(fd, &c, 1) > 0 && c != '\n')
        width++;
    close(fd);
    return width;
}

map_t *load_map(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd < 0)
        return NULL;
    int height = get_height(filepath);
    int width = get_width(filepath);
    map_t *map = malloc(sizeof(map_t));
    map->data = malloc(sizeof(int *) * height);
    map->height = height;
    map->width = width;
    for (int i = 0; i < height; i++) {
        map->data[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            char c;
            read(fd, &c, 1);
            map->data[i][j] = (c == '0') ? 0 : 1;
        }
        read(fd, &(char){0}, 1); // leer el '\n'
    }
    close(fd);
    return map;
}

void destroy_map(map_t *map)
{
    for (int i = 0; i < map->height; i++)
        free(map->data[i]);
    free(map->data);
    free(map);
}

int load_from_data(MapClass_t *self, map_t *data)
{
    if (!self || !data)
        return 84;
    if (self->map) {
        for (int i = 0; i < self->height; i++)
            free(self->map[i]);
        free(self->map);
    }
    self->map = data->map;
    self->width = data->width;
    self->height = data->height;
    free(data);
    return 0;
}
