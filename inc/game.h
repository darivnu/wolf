/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** game
*/

#include <SFML/System/Types.h>
#include "animation.h"
#include <SFML/Window/VideoMode.h>
#include "common.h"
#include "hud.h"
#include "input.h"
#include "map.h"
#include "oop.h"
#include "player.h"
#include "ray.h"
#include "render.h"
#include "sound.h"
#include "sprite.h"
#include "state_manager.h"
#include "texture.h"
#include "weapon.h"

#ifndef INCLUDED_GAME_H
    #define INCLUDED_GAME_H

typedef struct game_aux GameClass_t;

typedef struct game_aux {
    /* class metadata*/
    class_t meta;
    /* class members */
    /* ----Classes---- */
    RayClass_t *ray;
    PlayerClass_t *player;
    MapClass_t *map;
    RenderClass_t *render;
    InputClass_t *input;
    TextureClass_t *texture;
    AnimationClass_t *animation;
    SpriteClass_t *sprite;
    WeaponClass_t *weapon;
    SoundClass_t *sound;
    HUDClass_t *hud;
    StateManagerClass_t *state_manager;

    /* --------------- */
    sfVideoMode mode;
    int screenX;
    int screenWidth;
    int screenHeight;
    sfClock *clock;
    float deltaTime;
    int game_components_initialized;
    /* class methods */
    int (*init_game_components)(GameClass_t *game);
    void (*handle_events)(GameClass_t *game);
    void (*update_game)(GameClass_t *game);
    void (*render_game)(GameClass_t *game);
    void (*set_game_basic_components)(GameClass_t *game);
    void (*game_loop)(GameClass_t *game);
    void (*init_sound)(GameClass_t *game);

} GameClass_t;

int init_game_components(GameClass_t *);
void handle_events(GameClass_t *game);
void update_game(GameClass_t *game);
void render_game(GameClass_t *game);
void set_game_basic_components(GameClass_t *game);
void game_loop(GameClass_t *game);
void init_sound(GameClass_t *game);

extern const class_t *Game;
extern const class_t *Ray;
extern const class_t *Player;
extern const class_t *Map;
extern const class_t *Render;
extern const class_t *Input;
extern const class_t *Texture;
extern const class_t *Animation;
extern const class_t *Sprite;
extern const class_t *Weapon;
extern const class_t *Sound;
extern const class_t *HUD;
extern const class_t *StateManager;

#endif