/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** settings state implementation
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>
#include "game.h"
#include "state_manager.h"

static void create_volume_label(StateManagerClass_t *self, int index,
    const char *text, float y_pos)
{
    float font_size;

    self->volume_labels[index] = sfText_create();
    if (!self->menu_font) {
        self->menu_font = sfFont_createFromFile("assets/fonts/hp.ttf");
    }
    if (self->menu_font) {
        sfText_setFont(self->volume_labels[index], self->menu_font);
    }
    font_size = self->parent->screenHeight * 0.04f;
    sfText_setString(self->volume_labels[index], text);
    sfText_setCharacterSize(self->volume_labels[index], (unsigned int)font_size);
    sfText_setFillColor(self->volume_labels[index], sfWhite);
    sfText_setPosition(self->volume_labels[index],
        (sfVector2f){self->parent->screenWidth * 0.125f, y_pos});
}

static void create_volume_bar(StateManagerClass_t *self, int index,
    float y_pos)
{
    float bar_width, bar_height;

    bar_width = self->parent->screenWidth * 0.25f;
    bar_height = self->parent->screenHeight * 0.033f;
    self->volume_bars[index] = sfRectangleShape_create();
    sfRectangleShape_setSize(self->volume_bars[index],
        (sfVector2f){bar_width, bar_height});
    sfRectangleShape_setPosition(self->volume_bars[index],
        (sfVector2f){self->parent->screenWidth * 0.375f, y_pos});
    sfRectangleShape_setFillColor(self->volume_bars[index], sfGreen);
    sfRectangleShape_setOutlineThickness(self->volume_bars[index], 2);
    sfRectangleShape_setOutlineColor(self->volume_bars[index], sfWhite);
}

void init_settings(StateManagerClass_t *self)
{
    float center_x, button_y;
    float label_start_y, bar_spacing;

    self->settings_bg_texture =
        sfTexture_createFromFile("assets/menu/settings_background.png", NULL);
    if (!self->settings_bg_texture) {
        self->settings_bg_texture = create_fallback_background(
            self->parent->screenWidth, self->parent->screenHeight,
            (sfColor){60, 40, 40, 255});
    }
    self->settings_background = sfSprite_create();
    sfSprite_setTexture(
        self->settings_background, self->settings_bg_texture, sfTrue);
    sfSprite_setScale(self->settings_background,
        (sfVector2f){
            (float)self->parent->screenWidth / 
                sfTexture_getSize(self->settings_bg_texture).x,
            (float)self->parent->screenHeight / 
                sfTexture_getSize(self->settings_bg_texture).y
        });
    center_x = self->parent->screenWidth / 2.0f;
    button_y = self->parent->screenHeight * 0.85f;
    label_start_y = self->parent->screenHeight * 0.33f;
    bar_spacing = self->parent->screenHeight * 0.083f;
    create_volume_label(self, 0, "Master Volume:", label_start_y);
    create_volume_label(self, 1, "Effects Volume:", label_start_y + bar_spacing);
    create_volume_label(self, 2, "Music Volume:", label_start_y + bar_spacing * 2);
    create_volume_bar(self, 0, label_start_y);
    create_volume_bar(self, 1, label_start_y + bar_spacing);
    create_volume_bar(self, 2, label_start_y + bar_spacing * 2);
    self->buttons[BUTTON_BACK] =
        self->create_button(self, BUTTON_BACK,
            center_x - self->parent->screenWidth * 0.32f, button_y);
    self->buttons[BUTTON_APPLY] =
        self->create_button(self, BUTTON_APPLY,
            center_x + self->parent->screenWidth * 0.07f, button_y);
}

void update_settings(StateManagerClass_t *self, float delta_time)
{
    self->update_button_hover(self, self->buttons[BUTTON_BACK]);
    self->update_button_hover(self, self->buttons[BUTTON_APPLY]);
}

void render_settings(StateManagerClass_t *self)
{
    int i;

    if (self->settings_background) {
        sfRenderWindow_drawSprite(
            self->parent->render->window, self->settings_background, NULL);
    }
    for (i = 0; i < 3; i++) {
        if (self->volume_labels[i]) {
            sfRenderWindow_drawText(
                self->parent->render->window, self->volume_labels[i], NULL);
        }
        if (self->volume_bars[i]) {
            sfRenderWindow_drawRectangleShape(
                self->parent->render->window, self->volume_bars[i], NULL);
        }
    }
    self->render_button(self, self->buttons[BUTTON_BACK]);
    self->render_button(self, self->buttons[BUTTON_APPLY]);
}

static void apply_volume_settings(StateManagerClass_t *self)
{
    if (self->parent->sound) {
        self->parent->sound->set_master_volume(
            self->parent->sound, self->volume_values[0] / 100.0f);
        self->parent->sound->set_effect_volume(
            self->parent->sound, self->volume_values[1] / 100.0f);
        self->parent->sound->set_music_volume_global(
            self->parent->sound, self->volume_values[2] / 100.0f);
    }
}

void handle_settings_input(StateManagerClass_t *self)
{
    if (self->is_button_clicked(self, self->buttons[BUTTON_BACK])) {
        self->transition_to_state(self, GAME_MENU);
    }
    if (self->is_button_clicked(self, self->buttons[BUTTON_APPLY])) {
        apply_volume_settings(self);
    }
}