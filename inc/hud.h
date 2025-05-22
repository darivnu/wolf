/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** hud
*/

#include <SFML/Graphics/RectangleShape.h>
#include "oop.h"
#include "weapon.h"

#ifndef INCLUDED_HUD_H
    #define INCLUDED_HUD_H
typedef struct game_aux GameClass_t;
typedef struct HUD_aux HUDClass_t;
typedef struct sprite_aux SpriteClass_t;

typedef struct HUD_aux {
    /* class metadata*/
    class_t meta;
    /* class members */
    GameClass_t *parent;
    SpriteClass_t *stats;
    sfRectangleShape *health_bar;
    sfRectangleShape *mana_bar;
    float max_bar_width;
    float current_health;
    float current_mana;
    float last_mana_use_time;
    float mana_regen_delay;
    float mana_regen_rate;
    spell_type_t current_spell;
    /* class methods */
    void (*init_hud)(HUDClass_t *);
    void (*render_hud)(HUDClass_t *);
    void (*create_health_bar)(HUDClass_t *);
    void (*create_mana_bar)(HUDClass_t *);
    void (*update_health_bar)(HUDClass_t *, float);
    void (*update_mana_bar)(HUDClass_t *, float);
    void (*update_hud)(HUDClass_t *, float);
    void (*use_mana)(HUDClass_t *, float);
    void (*regenerate_mana)(HUDClass_t *, float);
    void (*switch_spell_hud)(HUDClass_t *, spell_type_t);
} HUDClass_t;

void init_hud(HUDClass_t *);
void render_hud(HUDClass_t *);
void create_health_bar(HUDClass_t *);
void create_mana_bar(HUDClass_t *);
void update_health_bar(HUDClass_t *, float);
void update_mana_bar(HUDClass_t *, float);
void update_hud(HUDClass_t *, float);
void use_mana(HUDClass_t *, float);
void regenerate_mana(HUDClass_t *, float);
void switch_spell_hud(HUDClass_t *, spell_type_t);


#endif