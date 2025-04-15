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
    // Player ray logic members
    double posX, posY;
    double dirX, dirY;
    double planeX, planeY;
    double moveSpeed;
    double rotSpeed;
    //
    double newPosX, newPosY;
    double newMoveSpeed;
    double newRotSpeed;
    /* class methods */
    void (*init_player)(PlayerClass_t *);
    void (*player_move)(PlayerClass_t *);
} PlayerClass_t;

void init_player(PlayerClass_t *);
void player_move(PlayerClass_t *);

#endif
