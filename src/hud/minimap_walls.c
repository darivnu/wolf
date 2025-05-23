/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** minimap_walls
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "game.h"

void update_wall_count(HUDClass_t *self, int *wall_count, int x, int y)
{
    if (self->parent->map->map_get_cell(self->parent->map, x, y) > 0) {
        (*wall_count)++;
    }
}

void setup_wall_sprite_texture(HUDClass_t *self, int wall_index,
    int wall_type)
{
    int texture_index = wall_type - 1;

    if (texture_index >= 0 && texture_index < NUM_TEXTURES &&
        self->parent->texture->wallTextures[texture_index]) {
        sfSprite_setTexture(self->minimap_walls[wall_index],
            self->parent->texture->wallTextures[texture_index], sfTrue);
    } else if (self->parent->texture->wallTextures[0]) {
        sfSprite_setTexture(self->minimap_walls[wall_index],
            self->parent->texture->wallTextures[0], sfTrue);
    }
}

void setup_wall_sprite_position(HUDClass_t *self, int wall_index,
    int x, int y, sfVector2f wall_scale)
{
    sfVector2f wall_pos;

    wall_pos.x = self->minimap_position.x +
        (x * MINIMAP_CELL_SIZE * self->minimap_scale);
    wall_pos.y = self->minimap_position.y +
        (y * MINIMAP_CELL_SIZE * self->minimap_scale);

    sfSprite_setScale(self->minimap_walls[wall_index], wall_scale);
    sfSprite_setPosition(self->minimap_walls[wall_index], wall_pos);
}

void cleanup_minimap_walls(HUDClass_t *self)
{
    int i = 0;

    if (!self->minimap_walls)
        return;
    for (i = 0; i < self->minimap_wall_count; i++) {
        if (self->minimap_walls[i])
            sfSprite_destroy(self->minimap_walls[i]);
    }
    free(self->minimap_walls);
    self->minimap_walls = NULL;
}