/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** input
*/

#include "common.h"
#include "oop.h"

#ifndef INCLUDED_INPUT_H
    #define INCLUDED_INPUT_H

typedef struct game_aux GameClass_t;
typedef struct input_aux InputClass_t;

typedef struct input_aux {
    /* class metadata */
    class_t meta;
    /* class members */
    GameClass_t *parent;
    double forward;
    double strafe;
    double rotate;
    /* class methods */
    void (*get_input)(InputClass_t *);
} InputClass_t;

void get_input(InputClass_t *);

#endif
