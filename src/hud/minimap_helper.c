/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** minimap_helper
*/

#include "game.h"

void update_minimap_direction(HUDClass_t *self)
{
    sfVector2f player_pos;
    sfVector2f direction_end;

    sfVertexArray_clear(self->minimap_direction);
    self->calculate_player_minimap_pos(self, &player_pos);
    self->calculate_direction_end_pos(self, player_pos, &direction_end);
    self->setup_direction_line(self, player_pos, direction_end);
}

void cleanup_minimap_player(HUDClass_t *self)
{
    if (!self->minimap_player)
        return;
    sfCircleShape_destroy(self->minimap_player);
    self->minimap_player = NULL;
}

void cleanup_minimap_direction(HUDClass_t *self)
{
    if (!self->minimap_direction)
        return;
    sfVertexArray_destroy(self->minimap_direction);
    self->minimap_direction = NULL;
}
