/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** ray
*/

#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    RayClass_t *self = (RayClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
}

void ray_cast(RayClass_t *self)
{
    self->cameraX =
        2.0 * self->parent->screenX / (double) self->parent->screenWidth - 1.0;
    self->rayDirX = self->parent->player->dirX
        + self->parent->player->planeX * self->cameraX;
    self->rayDirY = self->parent->player->dirY
        + self->parent->player->planeY * self->cameraX;
    self->mapX = (int) self->parent->player->posX;
    self->mapY = (int) self->parent->player->posY;
    self->deltaDistX =
        (self->rayDirX == 0) ? INFINITE : fabs(1 / self->rayDirX);
    self->deltaDistY =
        (self->rayDirY == 0) ? INFINITE : fabs(1 / self->rayDirY);
    self->calc_step(self);
}

void calc_step(RayClass_t *self)
{
    if (self->rayDirX < 0) {
        self->stepX = -1;
        self->sideDistX =
            (self->parent->player->posX - self->mapX) * self->deltaDistX;
    } else {
        self->stepX = 1;
        self->sideDistX =
            (self->mapX + 1.0 - self->parent->player->posX) * self->deltaDistX;
    }
    if (self->rayDirY < 0) {
        self->stepY = -1;
        self->sideDistY =
            (self->parent->player->posY - self->mapY) * self->deltaDistY;
    } else {
        self->stepY = 1;
        self->sideDistY =
            (self->mapY + 1.0 - self->parent->player->posY) * self->deltaDistY;
    }
}

void dda_algo(RayClass_t *self)
{
    while (self->hit == 0) {
        if (self->sideDistX < self->sideDistY) {
            self->sideDistX += self->deltaDistX;
            self->mapX += self->stepX;
            self->side = 0;
        } else {
            self->sideDistY += self->deltaDistY;
            self->mapY += self->stepY;
            self->side = 1;
        }
        //need to implement map logic things before
    }
}

const RayClass_t ray_init = {
    {
        ._size = sizeof ray_init,
        ._name = "RayClass_t",
        ._constructor = constructor,
    },
    .ray_cast = ray_cast,
    .calc_step = calc_step,
    .dda_algo = dda_algo,
};

const class_t *Ray = (const class_t *) &ray_init;
