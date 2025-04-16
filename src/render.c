/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** render
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/System/Vector2.h>
#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    RenderClass_t *self = (RenderClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
}

void render_walls(RenderClass_t *self)
{
    for (int x = 0; x < self->width; x++) {
        self->parent->ray->ray_cast(self->parent->ray, x);
        self->zBuffer[x] = self->parent->ray->perpWallDist;
        
        // Draw the textured wall
        self->parent->texture->draw_textured_wall(self->parent->texture, x);
    }
}

//For the moment I will test it with colors
void set_texture(RenderClass_t *self)
{
    switch (self->parent->ray->wallType) {
        case 1:
            self->wallColor = sfRed;
            break;
        case 2:
            self->wallColor = sfGreen;
            break;
        case 3:
            self->wallColor = sfBlue;
            break;
        default:
            self->wallColor = sfWhite;
            break;
    }
    if (self->parent->ray->side == 1) {
        self->wallColor.r /= 2;
        self->wallColor.g /= 2;
        self->wallColor.b /= 2;
    }
}

void draw_lines(RenderClass_t *self, int x)
{
    self->line[0].position = (sfVector2f){x, self->drawStart};
    self->line[0].color = self->wallColor;
    self->line[1].position = (sfVector2f) {x, self->drawEnd};
    self->line[1].color = self->wallColor;
    self->vertexArray = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(self->vertexArray, sfLines);
    sfVertexArray_append(self->vertexArray, self->line[0]);
    sfVertexArray_append(self->vertexArray, self->line[1]);
    sfRenderWindow_drawVertexArray(self->window, self->vertexArray, NULL);
    sfVertexArray_destroy(self->vertexArray);
}

const RenderClass_t render_init = {
    {
        ._size = sizeof render_init,
        ._name = "RenderClass_t",
        ._constructor = constructor,
    },
    .render_walls = render_walls,
    .set_texture = set_texture,
    .draw_lines = draw_lines,
};

const class_t *Render = (class_t *) &render_init;
