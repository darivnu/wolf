/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** state manager
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include "oop.h"

#ifndef INCLUDED_STATE_MANAGER_H
    #define INCLUDED_STATE_MANAGER_H

typedef struct game_aux GameClass_t;
typedef struct state_manager_aux StateManagerClass_t;
typedef struct menu_button menu_button_t;

typedef enum {
    GAME_MENU,
    GAME_SETTINGS,
    GAME_PLAYING
} game_state_t;

typedef enum {
    BUTTON_PLAY,
    BUTTON_SETTINGS,
    BUTTON_EXIT,
    BUTTON_BACK,
    BUTTON_APPLY,
    BUTTON_COUNT
} button_type_t;

typedef struct menu_button {
    sfSprite *sprite;
    sfTexture *texture_normal;
    sfTexture *texture_hover;
    sfVector2f position;
    sfVector2f size;
    button_type_t type;
    int is_hovered;
    int is_visible;
} menu_button_t;

typedef struct state_manager_aux {
    /* class metadata */
    class_t meta;
    /* class members */
    GameClass_t *parent;
    game_state_t current_state;
    game_state_t previous_state;
    /* menu components */
    sfSprite *menu_background;
    sfTexture *menu_bg_texture;
    menu_button_t *buttons[BUTTON_COUNT];
    sfFont *menu_font;
    /* settings components */
    sfSprite *settings_background;
    sfTexture *settings_bg_texture;
    sfText *volume_labels[3];
    sfRectangleShape *volume_bars[3];
    float volume_values[3];
    /* class methods */
    void (*init_state_manager)(StateManagerClass_t *);
    void (*update_state)(StateManagerClass_t *, float);
    void (*render_state)(StateManagerClass_t *);
    void (*handle_state_input)(StateManagerClass_t *);
    void (*transition_to_state)(StateManagerClass_t *, game_state_t);
    /* menu operations */
    void (*init_menu)(StateManagerClass_t *);
    void (*update_menu)(StateManagerClass_t *, float);
    void (*render_menu)(StateManagerClass_t *);
    void (*handle_menu_input)(StateManagerClass_t *);
    /* settings operations */
    void (*init_settings)(StateManagerClass_t *);
    void (*update_settings)(StateManagerClass_t *, float);
    void (*render_settings)(StateManagerClass_t *);
    void (*handle_settings_input)(StateManagerClass_t *);
    /* button management */
    menu_button_t *(*create_button)(StateManagerClass_t *, button_type_t,
        float, float);
    void (*update_button_hover)(StateManagerClass_t *, menu_button_t *);
    int (*is_button_clicked)(StateManagerClass_t *, menu_button_t *);
    void (*render_button)(StateManagerClass_t *, menu_button_t *);
    void (*cleanup_buttons)(StateManagerClass_t *);
    /* mouse cursor management */
    void (*set_cursor_visible)(StateManagerClass_t *, int);
    void (*center_mouse_cursor)(StateManagerClass_t *);
} StateManagerClass_t;

void init_state_manager(StateManagerClass_t *);
void update_state(StateManagerClass_t *, float);
void render_state(StateManagerClass_t *);
void handle_state_input(StateManagerClass_t *);
void transition_to_state(StateManagerClass_t *, game_state_t);

/* menu functions */
void init_menu(StateManagerClass_t *);
void update_menu(StateManagerClass_t *, float);
void render_menu(StateManagerClass_t *);
void handle_menu_input(StateManagerClass_t *);

/* settings functions */
void init_settings(StateManagerClass_t *);
void update_settings(StateManagerClass_t *, float);
void render_settings(StateManagerClass_t *);
void handle_settings_input(StateManagerClass_t *);

/* button functions */
menu_button_t *create_button(StateManagerClass_t *, button_type_t,
    float, float);
void update_button_hover(StateManagerClass_t *, menu_button_t *);
int is_button_clicked(StateManagerClass_t *, menu_button_t *);
void render_button(StateManagerClass_t *, menu_button_t *);
void cleanup_buttons(StateManagerClass_t *);

/* mouse cursor management */
void set_cursor_visible(StateManagerClass_t *, int);
void center_mouse_cursor(StateManagerClass_t *);

/* texture fallback functions */
sfTexture *create_fallback_button_texture(button_type_t, int);
sfTexture *create_fallback_background(int, int, sfColor);

extern const class_t *StateManager;

#endif