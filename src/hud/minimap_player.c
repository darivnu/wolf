/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** minimap_player
*/

#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Graphics/VertexArray.h>
#include <SFML/System/Vector2.h>
#include "game.h"

void create_minimap_player(HUDClass_t *self)
{
    self->minimap_player = sfCircleShape_create();
    sfCircleShape_setRadius(self->minimap_player, MINIMAP_PLAYER_SIZE);
    sfCircleShape_setOrigin(self->minimap_player,
        (sfVector2f){MINIMAP_PLAYER_SIZE, MINIMAP_PLAYER_SIZE});
    sfCircleShape_setFillColor(self->minimap_player, sfYellow);
    sfCircleShape_setOutlineThickness(self->minimap_player, 1.0f);
    sfCircleShape_setOutlineColor(self->minimap_player, sfBlack);
}

void update_minimap_player(HUDClass_t *self)
{
    sfVector2f player_minimap_pos;

    player_minimap_pos.x = self->minimap_position.x
        + (self->parent->player->posX * MINIMAP_CELL_SIZE
            * self->minimap_scale);
    player_minimap_pos.y = self->minimap_position.y
        + (self->parent->player->posY * MINIMAP_CELL_SIZE
            * self->minimap_scale);
    sfCircleShape_setPosition(self->minimap_player, player_minimap_pos);
}

void calculate_player_minimap_pos(HUDClass_t *self, sfVector2f *player_pos)
{
    player_pos->x = self->minimap_position.x
        + (self->parent->player->posX * MINIMAP_CELL_SIZE
            * self->minimap_scale);
    player_pos->y = self->minimap_position.y
        + (self->parent->player->posY * MINIMAP_CELL_SIZE
            * self->minimap_scale);
}

void calculate_direction_end_pos(
    HUDClass_t *self, sfVector2f player_pos, sfVector2f *direction_end)
{
    direction_end->x =
        player_pos.x + (self->parent->player->dirX * MINIMAP_DIR_LENGTH);
    direction_end->y =
        player_pos.y + (self->parent->player->dirY * MINIMAP_DIR_LENGTH);
}

void setup_direction_line(
    HUDClass_t *self, sfVector2f player_pos, sfVector2f direction_end)
{
    sfVertex direction_line[2];

    direction_line[0].position = player_pos;
    direction_line[0].color = sfRed;
    direction_line[1].position = direction_end;
    direction_line[1].color = sfRed;
    sfVertexArray_append(self->minimap_direction, direction_line[0]);
    sfVertexArray_append(self->minimap_direction, direction_line[1]);
}
