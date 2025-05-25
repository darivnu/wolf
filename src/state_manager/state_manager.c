/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** state manager implementation
*/

#include <stdlib.h>
#include "game.h"
#include "state_manager.h"

static void constructor(void *ptr, va_list *args)
{
    StateManagerClass_t *self = (StateManagerClass_t *) ptr;
    int i;

    self->parent = va_arg(*args, GameClass_t *);
    self->current_state = GAME_MENU;
    self->previous_state = GAME_MENU;
    self->menu_background = NULL;
    self->menu_bg_texture = NULL;
    self->settings_background = NULL;
    self->settings_bg_texture = NULL;
    self->menu_font = NULL;
    for (i = 0; i < BUTTON_COUNT; i++)
        self->buttons[i] = NULL;
    for (i = 0; i < 3; i++) {
        self->volume_labels[i] = NULL;
        self->volume_bars[i] = NULL;
        self->volume_values[i] = 50.0f;
    }
}

static void destructor(void *ptr)
{
    StateManagerClass_t *self = (StateManagerClass_t *) ptr;
    int i;

    self->cleanup_buttons(self);
    if (self->menu_background)
        sfSprite_destroy(self->menu_background);
    if (self->menu_bg_texture)
        sfTexture_destroy(self->menu_bg_texture);
    if (self->settings_background)
        sfSprite_destroy(self->settings_background);
    if (self->settings_bg_texture)
        sfTexture_destroy(self->settings_bg_texture);
    if (self->menu_font)
        sfFont_destroy(self->menu_font);
    for (i = 0; i < 3; i++) {
        if (self->volume_labels[i])
            sfText_destroy(self->volume_labels[i]);
        if (self->volume_bars[i])
            sfRectangleShape_destroy(self->volume_bars[i]);
    }
}

void init_state_manager(StateManagerClass_t *self)
{
    self->init_menu(self);
    self->init_settings(self);
    self->set_cursor_visible(self, 1);
}

void update_state(StateManagerClass_t *self, float delta_time)
{
    switch (self->current_state) {
        case GAME_MENU:
            self->update_menu(self, delta_time);
            break;
        case GAME_SETTINGS:
            self->update_settings(self, delta_time);
            break;
        case GAME_PLAYING:
            break;
    }
}

void render_state(StateManagerClass_t *self)
{
    switch (self->current_state) {
        case GAME_MENU:
            self->render_menu(self);
            break;
        case GAME_SETTINGS:
            self->render_settings(self);
            break;
        case GAME_PLAYING:
            break;
    }
}

void handle_state_input(StateManagerClass_t *self)
{
    switch (self->current_state) {
        case GAME_MENU:
            self->handle_menu_input(self);
            break;
        case GAME_SETTINGS:
            self->handle_settings_input(self);
            break;
        case GAME_PLAYING:
            break;
    }
}

void transition_to_state(StateManagerClass_t *self, game_state_t new_state)
{
    self->previous_state = self->current_state;
    self->current_state = new_state;
    if (new_state == GAME_PLAYING) {
        self->set_cursor_visible(self, 0);
        self->center_mouse_cursor(self);
    } else {
        self->set_cursor_visible(self, 1);
    }
}

void set_cursor_visible(StateManagerClass_t *self, int visible)
{
    sfRenderWindow_setMouseCursorVisible(
        self->parent->render->window, visible ? sfTrue : sfFalse);
    sfWindow_setMouseCursorGrabbed(
        (sfWindow *) self->parent->render->window, visible ? sfFalse : sfTrue);
}

void center_mouse_cursor(StateManagerClass_t *self)
{
    sfVector2i center_pos;

    center_pos.x = self->parent->screenWidth / 2;
    center_pos.y = self->parent->screenHeight / 2;
    sfMouse_setPositionRenderWindow(center_pos, self->parent->render->window);
}

const StateManagerClass_t state_manager_init = {
    {
        ._size = sizeof state_manager_init,
        ._name = "StateManagerClass_t",
        ._constructor = constructor,
        ._destructor = destructor,
    },
    .init_state_manager = init_state_manager,
    .update_state = update_state,
    .render_state = render_state,
    .handle_state_input = handle_state_input,
    .transition_to_state = transition_to_state,
    .init_menu = init_menu,
    .update_menu = update_menu,
    .render_menu = render_menu,
    .handle_menu_input = handle_menu_input,
    .init_settings = init_settings,
    .update_settings = update_settings,
    .render_settings = render_settings,
    .handle_settings_input = handle_settings_input,
    .create_button = create_button,
    .update_button_hover = update_button_hover,
    .is_button_clicked = is_button_clicked,
    .render_button = render_button,
    .cleanup_buttons = cleanup_buttons,
    .set_cursor_visible = set_cursor_visible,
    .center_mouse_cursor = center_mouse_cursor,
};

const class_t *StateManager = (const class_t *) &state_manager_init;