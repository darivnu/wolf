/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** texture
*/

#include <SFML/Config.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
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
    sfTexture **wallTextures;
    sfSprite *wallSprite;
    sfTexture *floorTexture;
    sfTexture *ceilingTexture;
    sfRenderTexture *floorCeilingTexture;
    sfColor floorColor;
    sfColor ceilingColor;
    int textureSize;
    int texNum;
    sfIntRect textureRect;
    float wallHeight;
    float posY;
    float rayDirX0, rayDirY0, rayDirX1, rayDirY1;
    float floorX, floorY, floorStepX, floorStepY;
    float rowDistance;
    int cellX, cellY, tx, ty;
    float posZ;
    sfImage *floorImage, *ceilingImage;
    sfUint8 *buffer;
    sfImage *fcImage;
    sfTexture * fcTexture;
    sfSprite *fcSprite;
    int position;
    /* class methods */
    void (*load_textures)(TextureClass_t *);
    void (*draw_textured_wall)(TextureClass_t *, int);
    void (*draw_floor_ceiling)(TextureClass_t *);
    void (*set_fc)(TextureClass_t *);
    void (*set_fc_pixels)(TextureClass_t *, int, int);
    void (*fc_loop)(TextureClass_t *, int);
    void (*fc_xloop)(TextureClass_t *, int);
    void (*fc_logic)(TextureClass_t *);
} TextureClass_t;

void load_textures(TextureClass_t *);
void draw_textured_wall(TextureClass_t *, int);
void draw_floor_ceiling(TextureClass_t *);
void set_fc(TextureClass_t *);
void set_fc_pixels(TextureClass_t *, int, int);
void fc_loop(TextureClass_t *, int);
void fc_xloop(TextureClass_t *, int);
void fc_logic(TextureClass_t *);

#endif
