/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** hud
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/VertexArray.h>
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
    SpriteClass_t *wizard;
    animation_data_t *wizard_animation;
    sfRectangleShape *health_bar;
    sfRectangleShape *mana_bar;
    float max_bar_width;
    float current_health;
    float current_mana;
    float last_mana_use_time;
    float mana_regen_delay;
    float mana_regen_rate;
    spell_type_t current_spell;
    /* minimap members */
    sfRectangleShape *minimap_background;
    sfSprite **minimap_walls;
    sfCircleShape *minimap_player;
    sfVertexArray *minimap_direction;
    int minimap_wall_count;
    float minimap_scale;
    sfVector2f minimap_position;
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
    /* minimap methods */
    void (*init_minimap)(HUDClass_t *);
    void (*render_minimap)(HUDClass_t *);
    void (*create_minimap_background)(HUDClass_t *);
    void (*create_minimap_walls)(HUDClass_t *);
    void (*create_minimap_player)(HUDClass_t *);
    void (*update_minimap_player)(HUDClass_t *);
    void (*update_minimap_direction)(HUDClass_t *);
    void (*cleanup_minimap)(HUDClass_t *);
    void (*update_wall_count)(HUDClass_t *, int *, int, int);
    void (*create_wall_sprites)(HUDClass_t *);
    void (*process_wall_cell)(HUDClass_t *, int, int, sfVector2f, int *);
    void (*setup_wall_sprite_texture)(HUDClass_t *, int, int);
    void (*setup_wall_sprite_position)(HUDClass_t *, int, int, int, sfVector2f);
    void (*cleanup_minimap_background)(HUDClass_t *);
    void (*cleanup_minimap_walls)(HUDClass_t *);
    void (*cleanup_minimap_player)(HUDClass_t *);
    void (*cleanup_minimap_direction)(HUDClass_t *);
    void (*calculate_player_minimap_pos)(HUDClass_t *, sfVector2f *);
    void (*calculate_direction_end_pos)(HUDClass_t *, sfVector2f, sfVector2f *);
    void (*setup_direction_line)(HUDClass_t *, sfVector2f, sfVector2f);
    void (*set_wizard_portrait_anim)(HUDClass_t *);
    void (*set_wizard_portrait_sprite)(HUDClass_t *);
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

/* minimap functions */
void init_minimap(HUDClass_t *);
void render_minimap(HUDClass_t *);
void create_minimap_background(HUDClass_t *);
void create_minimap_walls(HUDClass_t *);
void create_minimap_player(HUDClass_t *);
void update_minimap_player(HUDClass_t *);
void update_minimap_direction(HUDClass_t *);
void cleanup_minimap(HUDClass_t *);
void update_wall_count(HUDClass_t *, int *, int, int);
void create_wall_sprites(HUDClass_t *);
void process_wall_cell(HUDClass_t *, int, int, sfVector2f, int *);
void setup_wall_sprite_texture(HUDClass_t *, int, int);
void setup_wall_sprite_position(HUDClass_t *, int, int, int, sfVector2f);
void cleanup_minimap_background(HUDClass_t *);
void cleanup_minimap_walls(HUDClass_t *);
void cleanup_minimap_player(HUDClass_t *);
void cleanup_minimap_direction(HUDClass_t *);
void calculate_player_minimap_pos(HUDClass_t *, sfVector2f *);
void calculate_direction_end_pos(HUDClass_t *, sfVector2f, sfVector2f *);
void setup_direction_line(HUDClass_t *, sfVector2f, sfVector2f);
void set_wizard_portrait_anim(HUDClass_t *);
void set_wizard_portrait_sprite(HUDClass_t *);

#endif