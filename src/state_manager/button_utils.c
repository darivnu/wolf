/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** button management utilities
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Mouse.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "game.h"
#include "state_manager.h"

static const char *get_button_texture_path(button_type_t type, int is_hover)
{
    static const char *normal_paths[] = {
        "assets/menu/play_btn.png",
        "assets/menu/settings_btn.png",
        "assets/menu/exit_btn.png",
        "assets/menu/return_btn.png",
        "assets/menu/apply_btn.png",
    };
    static const char *hover_paths[] = {
        "assets/menu/play_btn.png",
        "assets/menu/settings_btn.png",
        "assets/menu/exit_btn.png",
        "assets/menu/return_btn.png",
        "assets/menu/apply_btn.png",
    };

    if (type >= BUTTON_COUNT)
        return NULL;
    return is_hover ? hover_paths[type] : normal_paths[type];
}

static void calculate_button_scale(StateManagerClass_t *self,
    menu_button_t *button)
{
    sfVector2u tex_size;
    float scale_x, scale_y;

    if (!button->texture_normal)
        return;
    tex_size = sfTexture_getSize(button->texture_normal);
    scale_x = button->size.x / tex_size.x;
    scale_y = button->size.y / tex_size.y;
    sfSprite_setScale(button->sprite, (sfVector2f){scale_x, scale_y});
}

menu_button_t *create_button(StateManagerClass_t *self, button_type_t type,
    float x, float y)
{
    menu_button_t *button;
    const char *normal_path;
    const char *hover_path;

    button = malloc(sizeof(menu_button_t));
    if (!button)
        return NULL;
    normal_path = get_button_texture_path(type, 0);
    hover_path = get_button_texture_path(type, 1);
    button->texture_normal = sfTexture_createFromFile(normal_path, NULL);
    button->texture_hover = sfTexture_createFromFile(hover_path, NULL);
    if (!button->texture_normal) {
        button->texture_normal = create_fallback_button_texture(type, 0);
    }
    if (!button->texture_hover) {
        button->texture_hover = create_fallback_button_texture(type, 1);
    }
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->texture_normal, sfTrue);
    button->position = (sfVector2f){x, y};
    button->size = (sfVector2f){
        self->parent->screenWidth * 0.25f,
        self->parent->screenHeight * 0.08f
    };
    button->type = type;
    button->is_hovered = 0;
    button->is_visible = 1;
    sfSprite_setPosition(button->sprite, button->position);
    calculate_button_scale(self, button);
    return button;
}

void update_button_hover(StateManagerClass_t *self, menu_button_t *button)
{
    sfVector2i mouse_pos;
    int was_hovered;

    if (!button || !button->is_visible)
        return;
    mouse_pos = sfMouse_getPositionRenderWindow(self->parent->render->window);
    was_hovered = button->is_hovered;
    button->is_hovered = (mouse_pos.x >= button->position.x
        && mouse_pos.x <= button->position.x + button->size.x
        && mouse_pos.y >= button->position.y
        && mouse_pos.y <= button->position.y + button->size.y);
    if (button->is_hovered != was_hovered) {
        sfTexture *new_texture = button->is_hovered
            ? button->texture_hover : button->texture_normal;
        sfSprite_setTexture(button->sprite, new_texture, sfTrue);
        calculate_button_scale(self, button);
    }
}

int is_button_clicked(StateManagerClass_t *self, menu_button_t *button)
{
    static int was_pressed = 0;
    int is_pressed;

    if (!button || !button->is_visible || !button->is_hovered)
        return 0;
    is_pressed = sfMouse_isButtonPressed(sfMouseLeft);
    if (!is_pressed && was_pressed) {
        was_pressed = 0;
        return 1;
    }
    was_pressed = is_pressed;
    return 0;
}

void render_button(StateManagerClass_t *self, menu_button_t *button)
{
    if (!button || !button->is_visible)
        return;
    sfRenderWindow_drawSprite(
        self->parent->render->window, button->sprite, NULL);
}

void cleanup_buttons(StateManagerClass_t *self)
{
    int i;

    for (i = 0; i < BUTTON_COUNT; i++) {
        if (self->buttons[i]) {
            if (self->buttons[i]->sprite)
                sfSprite_destroy(self->buttons[i]->sprite);
            if (self->buttons[i]->texture_normal)
                sfTexture_destroy(self->buttons[i]->texture_normal);
            if (self->buttons[i]->texture_hover
                && self->buttons[i]->texture_hover
                    != self->buttons[i]->texture_normal)
                sfTexture_destroy(self->buttons[i]->texture_hover);
            free(self->buttons[i]);
            self->buttons[i] = NULL;
        }
    }
}