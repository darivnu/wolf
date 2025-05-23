/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** minimap_walls_create
*/

#include "game.h"

void create_minimap_walls(HUDClass_t *self)
{
    int wall_count = 0;
    int x = 0;
    int y = 0;

    for (y = 0; y < self->parent->map->height; y++) {
        for (x = 0; x < self->parent->map->width; x++) {
            self->update_wall_count(self, &wall_count, x, y);
        }
    }
    self->minimap_wall_count = wall_count;
    if (wall_count == 0)
        return;
    self->minimap_walls = malloc(sizeof(sfSprite *) * wall_count);
    self->create_wall_sprites(self);
}

void create_wall_sprites(HUDClass_t *self)
{
    int wall_index = 0;
    int x = 0;
    int y = 0;
    sfVector2f wall_scale;

    wall_scale.x = (MINIMAP_CELL_SIZE * self->minimap_scale)
        / self->parent->texture->textureSize;
    wall_scale.y = (MINIMAP_CELL_SIZE * self->minimap_scale)
        / self->parent->texture->textureSize;
    for (y = 0; y < self->parent->map->height; y++) {
        for (x = 0; x < self->parent->map->width; x++) {
            self->process_wall_cell(
                self, (sfVector2i){x, y}, wall_scale, &wall_index);
        }
    }
}

void process_wall_cell(HUDClass_t *self, sfVector2i position,
    sfVector2f wall_scale, int *wall_index)
{
    int wall_type = 0;

    wall_type = self->parent->map->map_get_cell(
        self->parent->map, position.x, position.y);
    if (wall_type <= 0)
        return;
    self->minimap_walls[*wall_index] = sfSprite_create();
    self->setup_wall_sprite_texture(self, *wall_index, wall_type);
    self->setup_wall_sprite_position(self, *wall_index, position, wall_scale);
    (*wall_index)++;
}
