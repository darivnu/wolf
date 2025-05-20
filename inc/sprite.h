/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sprite
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Vector2.h>
#include "animation.h"
#include "oop.h"

#ifndef INCLUDED_SPRITE_H
    #define INCLUDED_SPRITE_H

typedef struct game_aux GameClass_t;
typedef struct sprite_aux SpriteClass_t;

typedef struct sprite_aux {
    /* class metadata */
    class_t meta;
    /* class members */
    GameClass_t *parent;
    sfSprite *sprite;
    sfTexture *texture;
    animation_data_t *current_animation;
    sfVector2f position;
    sfVector2f scale;
    float rotation;
    int visible;
    /* class methods */
    void (*load_texture)(SpriteClass_t *, const char *);
    void (*set_position)(SpriteClass_t *, float, float);
    void (*set_scale)(SpriteClass_t *, float, float);
    void (*set_rotation)(SpriteClass_t *, float);
    void (*set_visible)(SpriteClass_t *, int);
    void (*set_animation)(SpriteClass_t *, animation_data_t *);
    void (*update_sprite)(SpriteClass_t *, float);
    void (*draw_sprite)(SpriteClass_t *);
} SpriteClass_t;

void load_texture(SpriteClass_t *, const char *);
void set_position(SpriteClass_t *, float, float);
void set_scale(SpriteClass_t *, float, float);
void set_rotation(SpriteClass_t *, float);
void set_visible(SpriteClass_t *, int);
void set_animation(SpriteClass_t *, animation_data_t *);
void update_sprite(SpriteClass_t *, float);
void draw_sprite(SpriteClass_t *);

#endif
