/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** input
*/

#include <SFML/System/Vector2.h>
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
    sfVector2i currentMousePos;
    sfVector2i prevMousePos;
    int mouseDistance;
    int mouseThreshold;
    /* class methods */
    void (*get_input)(InputClass_t *);
    void (*mouse_rot)(InputClass_t *);
    void (*init_input_defaults)(InputClass_t *);
} InputClass_t;

void get_input(InputClass_t *);
void mouse_rot(InputClass_t *);
void init_input_defaults(InputClass_t *);

#endif
