/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** common
*/

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef INCLUDED_COMMON_H
    #define INCLUDED_COMMON_H
    /* DEFAULTS */
    #define DEFAULT_FOV       0.66
    #define DEFAULT_SPEED     4.0
    #define DEFAULT_ROT_SPEED 6.0
    #define DEFAULT_MOUSE_THRESHOLD 0
    /* ---------*/
    #define INFINITE          1e30
    #define WALL              1
    #define NOWALL            0
    #define NUM_TEXTURES 1

    /* BARS */
    #define BAR_SIZE 18
    #define BAR_X 223
    #define HEALTH_BAR_Y 30
    #define MANA_BAR_Y 63
    #define BAR_WIDTH_MAX 123.0f
    #define DEFAULT_MANA_REG_DELAY 4.0f
    #define DEFAULT_MANA_REG_RATE 20.0f

#endif
