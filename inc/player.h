/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** player
*/

#include "oop.h"
#ifndef INCLUDED_PLAYER_H
    #define INCLUDED_PLAYER_H

    typedef struct game_aux GameClass_t;
    typedef struct player_aux PlayerClass_t;

    typedef struct player_aux {
        /* class metadata */
        class_t meta;
        /* class members*/
        GameClass_t *parent;
        /* class methods */
    } PlayerClass_t;


#endif
