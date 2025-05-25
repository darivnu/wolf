/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** texture fallback creation utilities
*/

#include <SFML/Graphics/Image.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <stdlib.h>
#include <string.h>
#include "state_manager.h"

static sfTexture *create_button_texture(const char *text, sfColor bg_color,
    sfColor border_color, int width, int height)
{
    sfImage *image;
    sfTexture *texture;
    int x, y;
    int border_width = 3;

    image = sfImage_create(width, height);
    if (!image)
        return NULL;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (x < border_width || x >= width - border_width
                || y < border_width || y >= height - border_width) {
                sfImage_setPixel(image, x, y, border_color);
            } else {
                sfImage_setPixel(image, x, y, bg_color);
            }
        }
    }
    texture = sfTexture_createFromImage(image, NULL);
    sfImage_destroy(image);
    return texture;
}

sfTexture *create_fallback_button_texture(button_type_t type, int is_hover)
{
    static const char *button_names[] = {
        "PLAY", "SETTINGS", "EXIT", "BACK", "APPLY"
    };
    sfColor bg_normal = {80, 80, 80, 255};
    sfColor bg_hover = {120, 120, 120, 255};
    sfColor border = {255, 255, 255, 255};
    sfColor bg_color;

    if (type >= BUTTON_COUNT)
        return NULL;
    bg_color = is_hover ? bg_hover : bg_normal;
    return create_button_texture(button_names[type], bg_color, border, 200, 50);
}

sfTexture *create_fallback_background(int width, int height, sfColor color)
{
    sfImage *image;
    sfTexture *texture;
    int x, y;

    image = sfImage_create(width, height);
    if (!image)
        return NULL;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            sfImage_setPixel(image, x, y, color);
        }
    }
    texture = sfTexture_createFromImage(image, NULL);
    sfImage_destroy(image);
    return texture;
}