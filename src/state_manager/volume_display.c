/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** volume display enhancement
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "state_manager.h"

static void create_volume_percentage_text(StateManagerClass_t *self,
    int index, float y_pos)
{
    char percentage_str[8];
    float font_size;
    float text_x;

    if (self->volume_percentage_texts[index]) {
        sfText_destroy(self->volume_percentage_texts[index]);
    }
    self->volume_percentage_texts[index] = sfText_create();
    if (!self->menu_font) {
        self->menu_font = sfFont_createFromFile("assets/fonts/hp.ttf");
    }
    if (self->menu_font) {
        sfText_setFont(self->volume_percentage_texts[index], self->menu_font);
    }
    font_size = self->parent->screenHeight * 0.04f;
    sprintf(percentage_str, "%.0f%%", self->volume_values[index]);
    sfText_setString(self->volume_percentage_texts[index], percentage_str);
    sfText_setCharacterSize(self->volume_percentage_texts[index],
        (unsigned int)font_size);
    sfText_setFillColor(self->volume_percentage_texts[index], sfWhite);
    text_x = self->parent->screenWidth * 0.375f
        + self->parent->screenWidth * 0.25f + 20.0f;
    sfText_setPosition(self->volume_percentage_texts[index],
        (sfVector2f){text_x, y_pos});
}

void update_volume_percentage_display(StateManagerClass_t *self, int index)
{
    char percentage_str[8];

    if (!self->volume_percentage_texts[index])
        return;
    sprintf(percentage_str, "%.0f%%", self->volume_values[index]);
    sfText_setString(self->volume_percentage_texts[index], percentage_str);
}

void initialize_volume_percentage_texts(StateManagerClass_t *self)
{
    float label_start_y;
    float bar_spacing;

    label_start_y = self->parent->screenHeight * 0.33f;
    bar_spacing = self->parent->screenHeight * 0.083f;
    create_volume_percentage_text(self, 0, label_start_y);
    create_volume_percentage_text(self, 1, label_start_y + bar_spacing);
    create_volume_percentage_text(self, 2, label_start_y + bar_spacing * 2);
}

void render_volume_percentage_texts(StateManagerClass_t *self)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (self->volume_percentage_texts[i]) {
            sfRenderWindow_drawText(self->parent->render->window,
                self->volume_percentage_texts[i], NULL);
        }
    }
}

void cleanup_volume_percentage_texts(StateManagerClass_t *self)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (self->volume_percentage_texts[i]) {
            sfText_destroy(self->volume_percentage_texts[i]);
            self->volume_percentage_texts[i] = NULL;
        }
    }
}