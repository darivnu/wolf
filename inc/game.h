/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** game
*/

#include "common.h"
#include "oop.h"
#include "ray.h"
#include "player.h"

#ifndef INCLUDED_GAME_H
    #define INCLUDED_GAME_H

    typedef struct game_aux GameClass_t;

    typedef struct game_aux {
        /* class metadata*/
        class_t meta;
        /* class members */
        RayClass_t *ray;
        PlayerClass_t *player;
        /* class methods */
    } GameClass_t;

extern const class_t *Game;
extern const class_t *Ray;
extern const class_t *Player;

#endif
