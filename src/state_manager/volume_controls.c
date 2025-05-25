/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** volume controls implementation
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Vector2.h>
#include "game.h"
#include "state_manager.h"

static int is_mouse_over_volume_bar(StateManagerClass_t *self, int bar_index)
{
    sfVector2i mouse_pos;
    sfVector2f bar_pos;
    sfVector2f bar_size;

    if (!self->volume_bars[bar_index])
        return 0;
    mouse_pos = sfMouse_getPositionRenderWindow(self->parent->render->window);
    bar_pos = sfRectangleShape_getPosition(self->volume_bars[bar_index]);
    bar_size = sfRectangleShape_getSize(self->volume_bars[bar_index]);
    return (mouse_pos.x >= bar_pos.x && mouse_pos.x <= bar_pos.x + bar_size.x
        && mouse_pos.y >= bar_pos.y && mouse_pos.y <= bar_pos.y + bar_size.y);
}

static void update_volume_from_mouse(StateManagerClass_t *self, int bar_index)
{
    sfVector2i mouse_pos;
    sfVector2f bar_pos;
    sfVector2f bar_size;
    float relative_pos;
    float new_volume;

    if (!self->volume_bars[bar_index])
        return;
    mouse_pos = sfMouse_getPositionRenderWindow(self->parent->render->window);
    bar_pos = sfRectangleShape_getPosition(self->volume_bars[bar_index]);
    bar_size = sfRectangleShape_getSize(self->volume_bars[bar_index]);
    relative_pos = (mouse_pos.x - bar_pos.x) / bar_size.x;
    if (relative_pos < 0.0f)
        relative_pos = 0.0f;
    if (relative_pos > 1.0f)
        relative_pos = 1.0f;
    new_volume = relative_pos * 100.0f;
    self->volume_values[bar_index] = new_volume;
    self->update_volume_bar_visual(self, bar_index);
    self->update_volume_percentage_display(self, bar_index);
    self->apply_volume_change(self, bar_index);
}

void update_volume_bar_visual(StateManagerClass_t *self, int bar_index)
{
    sfVector2f full_size;
    sfVector2f current_size;
    float percentage;

    if (!self->volume_bars[bar_index])
        return;
    full_size.x = self->parent->screenWidth * 0.25f;
    full_size.y = self->parent->screenHeight * 0.033f;
    percentage = self->volume_values[bar_index] / 100.0f;
    current_size.x = full_size.x * percentage;
    current_size.y = full_size.y;
    sfRectangleShape_setSize(self->volume_bars[bar_index], current_size);
}

void apply_volume_change(StateManagerClass_t *self, int bar_index)
{
    float volume_percentage;

    volume_percentage = self->volume_values[bar_index] / 100.0f;
    switch (bar_index) {
        case 0:
            self->parent->sound->set_master_volume(
                self->parent->sound, volume_percentage);
            printf("Master volume set to %.1f%%\n", self->volume_values[bar_index]);
            break;
        case 1:
            self->parent->sound->set_effect_volume(
                self->parent->sound, volume_percentage);
            printf("Effects volume set to %.1f%%\n", self->volume_values[bar_index]);
            break;
        case 2:
            self->parent->sound->set_music_volume_global(
                self->parent->sound, volume_percentage);
            printf("Music volume set to %.1f%%\n", self->volume_values[bar_index]);
            break;
    }
}

void handle_volume_bar_interaction(StateManagerClass_t *self)
{
    static int dragging_bar = -1;
    static int was_mouse_pressed = 0;
    int is_mouse_pressed;
    int i;

    is_mouse_pressed = sfMouse_isButtonPressed(sfMouseLeft);
    if (is_mouse_pressed && !was_mouse_pressed) {
        for (i = 0; i < 3; i++) {
            if (is_mouse_over_volume_bar(self, i)) {
                dragging_bar = i;
                update_volume_from_mouse(self, i);
                break;
            }
        }
    } else if (!is_mouse_pressed && was_mouse_pressed) {
        dragging_bar = -1;
    } else if (is_mouse_pressed && dragging_bar >= 0) {
        update_volume_from_mouse(self, dragging_bar);
    }
    was_mouse_pressed = is_mouse_pressed;
}

void initialize_volume_values(StateManagerClass_t *self)
{
    self->volume_values[0] = 50.0f;
    self->volume_values[1] = 50.0f;
    self->volume_values[2] = 50.0f;
    self->initialize_volume_percentage_texts(self);
    self->update_volume_bar_visual(self, 0);
    self->update_volume_bar_visual(self, 1);
    self->update_volume_bar_visual(self, 2);
    self->update_volume_percentage_display(self, 0);
    self->update_volume_percentage_display(self, 1);
    self->update_volume_percentage_display(self, 2);
    self->apply_volume_change(self, 0);
    self->apply_volume_change(self, 1);
    self->apply_volume_change(self, 2);
}