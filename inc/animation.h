/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** animation
*/

#include <SFML/Graphics/Rect.h>
#include "oop.h"

#ifndef INCLUDED_ANIMATION_H
    #define INCLUDED_ANIMATION_H

typedef struct game_aux GameClass_t;
typedef struct animation_aux AnimationClass_t;
typedef struct animation_data animation_data_t;
typedef struct animation_frame animation_frame_t;

typedef enum {
    ANIM_LOOP,
    ANIM_ONCE,
    ANIM_PINGPONG,
} animation_type_t;

typedef enum {
    ANIM_STATE_IDLE,
    ANIM_STATE_FIRING,
    ANIM_STATE_TRANSITIONING
} weapon_anim_state_t;

typedef struct animation_frame {
    float duration;
    sfIntRect rect;
} animation_frame_t;

typedef struct animation_data {
    char *name;
    animation_type_t type;
    int frame_count;
    animation_frame_t *frames;
    float total_duration;
    int is_playing;
    float current_time;
    int current_frame;
    int direction;
} animation_data_t;

typedef struct animation_aux {
    /* class metadata */
    class_t meta;
    /* class members */
    GameClass_t *parent;
    animation_data_t **animations;
    weapon_anim_state_t weapon_animation_state;
    int animation_count;
    /* class methods */
    animation_data_t *(*create_animation)(
        AnimationClass_t *, const char *, animation_type_t);
    void (*add_frame)(
        AnimationClass_t *, animation_data_t *, float, sfIntRect);
    void (*update_animations)(AnimationClass_t *, float);
    void (*play_animation)(AnimationClass_t *, const char *);
    void (*stop_animation)(AnimationClass_t *, const char *);
    void (*reset_animation)(AnimationClass_t *, const char *);
    animation_data_t *(*get_animation)(AnimationClass_t *, const char *);
} AnimationClass_t;

animation_data_t *create_animation(
    AnimationClass_t *, const char *, animation_type_t);
void add_frame(AnimationClass_t *, animation_data_t *, float, sfIntRect);
void update_animations(AnimationClass_t *, float);
void play_animation(AnimationClass_t *, const char *);
void stop_animation(AnimationClass_t *, const char *);
void reset_animation(AnimationClass_t *, const char *);
animation_data_t *get_animation(AnimationClass_t *, const char *);

void init_animation_data(animation_data_t *, const char *, animation_type_t);
void update_animation(animation_data_t *, float);
void advance_animation_frame(animation_data_t *);
void handle_pingpong_animation(animation_data_t *);

#endif
