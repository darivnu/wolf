/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** weapon
*/

#include <SFML/Graphics/Sprite.h>
#include "animation.h"
#include "oop.h"

#ifndef INCLUDED_WEAPON_H
    #define INCLUDED_WEAPON_H

typedef struct game_aux GameClass_t;
typedef struct weapon_aux WeaponClass_t;
typedef struct sprite_aux SpriteClass_t;

typedef enum {
    WEAPON_STATE_IDLE,
    WEAPON_STATE_FIRING,
    WEAPON_STATE_TRANSITIONING
} weapon_state_t;

typedef enum {
    SPELL_TYPE_BLUE,
    SPELL_TYPE_ORANGE,
} spell_type_t;

typedef struct weapon_aux {
    /* class metadata */
    class_t meta;
    /* class members */
    GameClass_t *parent;
    SpriteClass_t *weapon_sprite;
    weapon_state_t state;
    spell_type_t current_spell;
    float transition_timer;
    /* class methods */
    void (*init_weapon)(WeaponClass_t *);
    void (*load_animations)(WeaponClass_t *);
    void (*create_idle_animation)(WeaponClass_t *, int, int);
    void (*create_fire_animation)(WeaponClass_t *, int, int);
    void (*setup_weapon_sprite)(WeaponClass_t *, int);
    void (*update)(WeaponClass_t *, float);
    void (*handle_input)(WeaponClass_t *);
    void (*handle_idle_state)(
        WeaponClass_t *, animation_data_t *, animation_data_t *);
    void (*handle_firing_state)(WeaponClass_t *, animation_data_t *);
    void (*handle_transition_state)(WeaponClass_t *, animation_data_t *);
    void (*render)(WeaponClass_t *);
    void (*switch_spell)(WeaponClass_t *, spell_type_t);
    void (*handle_spell_switch)(WeaponClass_t *);
} WeaponClass_t;

void init_weapon(WeaponClass_t *);
void load_weapon_animations(WeaponClass_t *);
void create_idle_animation(WeaponClass_t *, int, int);
void create_fire_animation(WeaponClass_t *, int, int);
void setup_weapon_sprite(WeaponClass_t *, int);
void update_weapon(WeaponClass_t *, float);
void handle_weapon_input(WeaponClass_t *);
void handle_idle_state(
    WeaponClass_t *, animation_data_t *, animation_data_t *);
void handle_firing_state(WeaponClass_t *, animation_data_t *);
void handle_transition_state(WeaponClass_t *, animation_data_t *);
void render_weapon(WeaponClass_t *);
void switch_spell(WeaponClass_t *, spell_type_t);
void handle_spell_switch(WeaponClass_t *);

extern const class_t *Weapon;

#endif
