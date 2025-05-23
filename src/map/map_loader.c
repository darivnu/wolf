/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** map_loader
*/

#include "game.h"

int load_map_row(MapClass_t *self, FILE *file, int row)
{
    int x;

    for (x = 0; x < self->width; x++) {
        if (fscanf(file, "%d", &self->data[row][x]) != 1) {
            return 84;
        }
    }
    return 0;
}

int load_map_data(MapClass_t *self, FILE *file)
{
    int y;
    int result;

    for (y = 0; y < self->height; y++) {
        result = load_map_row(self, file, y);
        if (result != 0) {
            self->map_cleanup(self);
            return 84;
        }
    }
    return 0;
}

FILE *open_map_file(const char *filepath)
{
    if (!filepath)
        return NULL;
    return fopen(filepath, "r");
}

int process_map_file(MapClass_t *self, FILE *file)
{
    int result;

    result = parse_map_header(file, &self->width, &self->height);
    if (result != 0)
        return result;
    result = allocate_map_data(self);
    if (result != 0)
        return result;
    return load_map_data(self, file);
}

int map_load_from_file(MapClass_t *self, const char *filepath)
{
    FILE *file;
    int result;

    file = open_map_file(filepath);
    if (!file)
        return 84;
    self->map_cleanup(self);
    result = process_map_file(self, file);
    fclose(file);
    return result;
}
