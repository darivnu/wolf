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
        /* class methods */
        void (*castRay)(RayClass_t *);
    } RayClass_t;

    void castRay(RayClass_t *);



#endif
