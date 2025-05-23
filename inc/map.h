/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** map
*/

#include "oop.h"
#include "common.h"

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
    int (*map_load_from_file)(MapClass_t *, const char *);
    void (*map_cleanup)(MapClass_t *);
    int (*parse_map_header)(FILE *, int *, int *);
    int (*allocate_map_data)(MapClass_t *);
    int (*load_map_data)(MapClass_t *, FILE *);
    int (*load_map_row)(MapClass_t *, FILE *, int);
    FILE *(*open_map_file)(const char *);
    int (*process_map_file)(MapClass_t *, FILE *);
} MapClass_t;

void map_create(MapClass_t *, int, int);
int map_get_cell(MapClass_t *, int, int);
int map_load_from_file(MapClass_t *, const char *);
void map_cleanup(MapClass_t *);
int parse_map_header(FILE *, int *, int *);
int allocate_map_data(MapClass_t *);
int load_map_data(MapClass_t *, FILE *);
int load_map_row(MapClass_t *, FILE *, int);
FILE *open_map_file(const char *);
int process_map_file(MapClass_t *, FILE *);

#endif
