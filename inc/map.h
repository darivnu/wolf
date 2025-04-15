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

typedef struct map_aux {
    /* class metadata */
    class_t meta;
    /* class members */
    GameClass_t *parent;
    int width;
    int height;
    int **data;
    /* class methods */
    void (*map_create)(MapClass_t *, int, int);
    int (*map_get_cell)(MapClass_t *, int, int);
} MapClass_t;

void map_create(MapClass_t *, int, int);
int map_get_cell(MapClass_t *, int, int);

#endif
