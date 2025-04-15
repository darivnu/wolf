/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** render
*/

#include "oop.h"

#ifndef INCLUDED_RENDER_H
    #define INCLUDED_RENDER_H

    typedef struct game_aux GameClass_t;
    typedef struct render_aux RenderClass_t;

    typedef struct render_aux {
        /* class metadata */
        class_t meta;
        /* class members */
        GameClass_t *parent;
        /* class methods */
    } RenderClass_t;

#endif
