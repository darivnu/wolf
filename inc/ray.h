/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** ray
*/

#include "oop.h"

#ifndef INCLUDED_RAY_H
    #define INCLUDED_RAY_H

typedef struct game_aux GameClass_t;
typedef struct ray_aux RayClass_t;

typedef struct ray_aux {
    /* class metadata*/
    class_t meta;
    /* class members */
    GameClass_t *parent;
    double rayDirX, rayDirY;
    double sideDistX, sideDistY;
    double deltaDistX, deltaDistY;
    int mapX, mapY;
    int stepX, stepY;
    int side;
    double perpWallDist;
    double cameraX;
    int hit;
    int wallType;
    double wallX;
    int texX;
    /* class methods */
    void (*ray_cast)(RayClass_t *, int);
    void (*calc_step)(RayClass_t *);
    void (*dda_algo)(RayClass_t *);
    void (*calc_perp_dist)(RayClass_t *);
    void (*set_walls)(RayClass_t *);
    void (*ray_destroy)(RayClass_t *);
} RayClass_t;

void ray_cast(RayClass_t *, int);
void calc_step(RayClass_t *);
void dda_algo(RayClass_t *);
void calc_perp_dist(RayClass_t *);
void set_walls(RayClass_t *);
void ray_destroy(RayClass_t *);

#endif
