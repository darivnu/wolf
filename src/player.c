/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** player
*/

#include "../inc/game.h"

static void constructor(void *ptr, va_list *args)
{
    PlayerClass_t *self = (PlayerClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
}

void init_player(PlayerClass_t *self)
{
    self->planeX = -self->dirY * DEFAULT_FOV;
    self->planeY = self->dirX * DEFAULT_FOV;
    self->moveSpeed = DEFAULT_SPEED;
    self->rotSpeed = DEFAULT_ROT_SPEED;
}

void player_move(PlayerClass_t *self)
{
    self->newMoveSpeed = self->moveSpeed * self->parent->deltaTime;
    self->newPosX = self->posX;
    self->newPosY = self->posY;
    if (self->parent->input->forward != 0) {
        self->newPosX = self->posX
            + self->dirX * self->newMoveSpeed * self->parent->input->forward;
        self->newPosY = self->posY
            + self->dirY * self->newMoveSpeed * self->parent->input->forward;
    }
    if (self->parent->input->strafe != 0) {
        self->newPosX = self->newPosX
            + self->planeX * self->newMoveSpeed * self->parent->input->strafe;
        self->newPosY = self->newPosY
            + self->planeY * self->newMoveSpeed * self->parent->input->strafe;
    }
    self->check_move_col(self);
}

void check_move_col(PlayerClass_t *self)
{
    if (self->parent->map->map_get_cell(
            self->parent->map, (int) self->newPosX, (int) self->posY)
        == 0) {
        self->posX = self->newPosX;
    }
    if (self->parent->map->map_get_cell(
            self->parent->map, (int) self->posX, (int) self->newPosY)
        == 0) {
        self->posY = self->newPosY;
    }
}

void player_rotate(PlayerClass_t *self)
{
    double rotSpeed =
        self->rotSpeed * self->parent->deltaTime * self->parent->input->rotate;
    double oldDirX = self->dirX;
    double oldPlaneX = self->planeX;

    self->dirX = self->dirX * cos(rotSpeed) - self->dirY * sin(rotSpeed);
    self->dirY = oldDirX * sin(rotSpeed) + self->dirY * cos(rotSpeed);
    self->planeX = self->planeX * cos(rotSpeed) - self->planeY * sin(rotSpeed);
    self->planeY = oldPlaneX * sin(rotSpeed) + self->planeY * cos(rotSpeed);
}

const PlayerClass_t player_init = {
    {
        ._size = sizeof player_init,
        ._name = "PlayerClass_t",
        ._constructor = constructor,
    },
    .init_player = init_player,
    .player_move = player_move,
    .check_move_col = check_move_col,
    .player_rotate = player_rotate,
};

const class_t *Player = (class_t *) &player_init;
