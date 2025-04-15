/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** render
*/

#include <SFML/Graphics/Types.h>
#include "oop.h"
#include "common.h"

#ifndef INCLUDED_RENDER_H
    #define INCLUDED_RENDER_H

    typedef struct game_aux GameClass_t;
    typedef struct render_aux RenderClass_t;

    typedef struct render_aux {
        /* class metadata */
        class_t meta;
        /* class members */
        GameClass_t *parent;
        sfRenderWindow *window;
        int width;
        int height;
        sfTexture **wallTextures;
        int textureSize;
        double *zBuffer;
        int lineHeight;
        int drawStart, drawEnd;
        sfColor wallColor;
        sfVertex line[2];
        sfVertexArray *vertexArray;
        /* class methods */
        void (*render_walls)(RenderClass_t *);
        void (*set_texture)(RenderClass_t *);
        void (*draw_lines)(RenderClass_t *, int);
    } RenderClass_t;

    void render_walls(RenderClass_t *);
    void set_texture(RenderClass_t *);
    void draw_lines(RenderClass_t *, int);

#endif
