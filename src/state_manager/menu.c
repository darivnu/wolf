/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** menu state implementation
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>
#include "game.h"
#include "state_manager.h"

static void calculate_responsive_positions(StateManagerClass_t *self,
    float *button_width, float *button_height, float *center_x, float *start_y)
{
    *button_width = self->parent->screenWidth * 0.25f;
    *button_height = self->parent->screenHeight * 0.08f;
    *center_x = (self->parent->screenWidth - *button_width) / 2.0f;
    *start_y = self->parent->screenHeight * 0.55f;
}

void init_menu(StateManagerClass_t *self)
{
    float button_width, button_height, center_x, start_y;
    float button_spacing;

    self->menu_bg_texture =
        sfTexture_createFromFile("assets/menu/menu_background.png", NULL);
    if (!self->menu_bg_texture) {
        self->menu_bg_texture = create_fallback_background(
            self->parent->screenWidth, self->parent->screenHeight,
            (sfColor){40, 40, 60, 255});
    }
    self->menu_background = sfSprite_create();
    sfSprite_setTexture(self->menu_background, self->menu_bg_texture, sfTrue);
    sfSprite_setScale(self->menu_background, 
        (sfVector2f){
            (float)self->parent->screenWidth / 
                sfTexture_getSize(self->menu_bg_texture).x,
            (float)self->parent->screenHeight / 
                sfTexture_getSize(self->menu_bg_texture).y
        });
    calculate_responsive_positions(self, &button_width, &button_height,
        &center_x, &start_y);
    button_spacing = button_height * 1.5f;
    self->buttons[BUTTON_PLAY] =
        self->create_button(self, BUTTON_PLAY, center_x, start_y);
    self->buttons[BUTTON_SETTINGS] =
        self->create_button(self, BUTTON_SETTINGS, center_x,
            start_y + button_spacing);
    self->buttons[BUTTON_EXIT] =
        self->create_button(self, BUTTON_EXIT, center_x,
            start_y + button_spacing * 2);
}

void update_menu(StateManagerClass_t *self, float delta_time)
{
    int i;

    for (i = 0; i < BUTTON_COUNT; i++) {
        if (self->buttons[i] && self->buttons[i]->is_visible) {
            self->update_button_hover(self, self->buttons[i]);
        }
    }
}

void render_menu(StateManagerClass_t *self)
{
    int i;

    if (self->menu_background) {
        sfRenderWindow_drawSprite(
            self->parent->render->window, self->menu_background, NULL);
    }
    for (i = 0; i < BUTTON_COUNT; i++) {
        if (self->buttons[i] && self->buttons[i]->is_visible) {
            self->render_button(self, self->buttons[i]);
        }
    }
}

static void handle_play_button(StateManagerClass_t *self)
{
    self->transition_to_state(self, GAME_PLAYING);
    self->parent->set_game_basic_components(self->parent);
    self->parent->weapon->init_weapon(self->parent->weapon);
    self->parent->hud->init_hud(self->parent->hud);
}

static void handle_settings_button(StateManagerClass_t *self)
{
    self->transition_to_state(self, GAME_SETTINGS);
}

static void handle_exit_button(StateManagerClass_t *self)
{
    sfRenderWindow_close(self->parent->render->window);
}

void handle_menu_input(StateManagerClass_t *self)
{
    if (self->is_button_clicked(self, self->buttons[BUTTON_PLAY])) {
        handle_play_button(self);
    }
    if (self->is_button_clicked(self, self->buttons[BUTTON_SETTINGS])) {
        handle_settings_button(self);
    }
    if (self->is_button_clicked(self, self->buttons[BUTTON_EXIT])) {
        handle_exit_button(self);
    }
}