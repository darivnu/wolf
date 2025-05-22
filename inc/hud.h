/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** hud
*/

#include "oop.h"

#ifndef INCLUDED_HUD_H
    #define INCLUDED_HUD_H
typedef struct game_aux GameClass_t;
typedef struct HUD_aux HUDClass_t;
typedef struct sprite_aux SpriteClass_t;

typedef struct HUD_aux {
    /* class metadata*/
    class_t meta;
    /* class members */
    GameClass_t *parent;
    SpriteClass_t *stats;
    /* class methods */
    void (*init_hud)(HUDClass_t *);
} HUDClass_t;

void init_hud(HUDClass_t *);


#endif
