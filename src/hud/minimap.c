/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** minimap
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/System/Vector2.h>
#include "game.h"

void init_minimap(HUDClass_t *self)
{
    float screen_width = (float) self->parent->screenWidth;

    self->minimap_position.x = screen_width - MINIMAP_SIZE - MINIMAP_MARGIN;
    self->minimap_position.y = MINIMAP_MARGIN;
    self->minimap_scale = (float) MINIMAP_SIZE
        / (float) (self->parent->map->width * MINIMAP_CELL_SIZE);
    self->create_minimap_background(self);
    self->create_minimap_walls(self);
    self->create_minimap_player(self);
    self->minimap_direction = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(self->minimap_direction, sfLines);
}

void create_minimap_background(HUDClass_t *self)
{
    self->minimap_background = sfRectangleShape_create();
    sfRectangleShape_setSize(
        self->minimap_background, (sfVector2f){MINIMAP_SIZE, MINIMAP_SIZE});
    sfRectangleShape_setPosition(
        self->minimap_background, self->minimap_position);
    sfRectangleShape_setFillColor(
        self->minimap_background, (sfColor){30, 30, 30, 200});
    sfRectangleShape_setOutlineThickness(self->minimap_background, 2.0f);
    sfRectangleShape_setOutlineColor(self->minimap_background, sfWhite);
}

void render_minimap(HUDClass_t *self)
{
    int i = 0;

    if (!self->minimap_background)
        return;
    sfRenderWindow_drawRectangleShape(
        self->parent->render->window, self->minimap_background, NULL);
    for (i = 0; i < self->minimap_wall_count; i++) {
        if (self->minimap_walls[i])
            sfRenderWindow_drawSprite(
                self->parent->render->window, self->minimap_walls[i], NULL);
    }
    if (self->minimap_player)
        sfRenderWindow_drawCircleShape(
            self->parent->render->window, self->minimap_player, NULL);
    if (self->minimap_direction)
        sfRenderWindow_drawVertexArray(
            self->parent->render->window, self->minimap_direction, NULL);
}

void cleanup_minimap(HUDClass_t *self)
{
    self->cleanup_minimap_background(self);
    self->cleanup_minimap_walls(self);
    self->cleanup_minimap_player(self);
    self->cleanup_minimap_direction(self);
}

void cleanup_minimap_background(HUDClass_t *self)
{
    if (!self->minimap_background)
        return;
    sfRectangleShape_destroy(self->minimap_background);
    self->minimap_background = NULL;
}
