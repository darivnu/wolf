/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** texture
*/

#include "oop.h"

#ifndef INCLUDED_TEXTURE_H
    #define INCLUDED_TEXTURE_H

typedef struct game_aux GameClass_t;
typedef struct texture_aux TextureClass_t;

typedef struct texture_aux {
    /* class metadata */
    class_t meta;
    /* class members */
    GameClass_t *parent;
    /* class methods */
} TextureClass_t;

#endif
