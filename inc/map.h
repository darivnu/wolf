/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** map
*/

#include "oop.h"

#ifndef INCLUDED_MAP_H
    #define INCLUDED_MAP_H

    typedef struct game_aux GameClass_t;
    typedef struct map_aux MapClass_t;
    

typedef struct map_s {
    int **data;
    int width;
    int height;
    int **map;
} map_t;

typedef struct map_aux {
    class_t meta;
    GameClass_t *parent;
    int width;
    int height;
    int **map;
    int **data;
    void (*map_create)(MapClass_t *, int, int);
    int (*map_get_cell)(MapClass_t *, int, int);
    int (*load_from_data)(MapClass_t *self, map_t *data);
} MapClass_t;

map_t *load_map(const char *filepath);
void destroy_map(map_t *map);
int load_from_data(MapClass_t *self, map_t *data);
void map_create(MapClass_t *, int, int);
int map_get_cell(MapClass_t *, int, int);

#endif
