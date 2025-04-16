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

void ray_cast(RayClass_t *self, int x)
{
    self->cameraX =
        2.0 * x / (double) self->parent->screenWidth - 1.0;
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
    self->dda_algo(self);
    self->calc_perp_dist(self);
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
    self->hit = 0;
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
        if (self->parent->map->map_get_cell(
                self->parent->map, self->mapX, self->mapY)
            > 0) {
            self->hit = 1;
            self->wallType = self->parent->map->map_get_cell(
                self->parent->map, self->mapX, self->mapY);
        }
    }
}

void calc_perp_dist(RayClass_t *self)
{
    if (self->side == 0) {
        self->perpWallDist =
            (self->mapX - self->parent->player->posX + (1 - self->stepX) / 2)
            / self->rayDirX;
    } else {
        self->perpWallDist =
            (self->mapY - self->parent->player->posY + (1 - self->stepY) / 2)
            / self->rayDirY;
    }
}

void ray_destroy(RayClass_t *self)
{
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
    .calc_perp_dist = calc_perp_dist,
    .ray_destroy = ray_destroy,
};

const class_t *Ray = (const class_t *) &ray_init;
