/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** texture_fc_utils
*/

#include "game.h"

void set_fc(TextureClass_t *self)
{
    self->rayDirX0 = self->parent->player->dirX - self->parent->player->planeX;
    self->rayDirY0 = self->parent->player->dirY - self->parent->player->planeY;
    self->rayDirX1 = self->parent->player->dirX + self->parent->player->planeX;
    self->rayDirY1 = self->parent->player->dirY + self->parent->player->planeY;
    self->posZ = 0.5 * self->parent->render->height;
}

void fc_loop(TextureClass_t *self, int y)
{
    self->position = y - self->parent->render->height / 2;
    if (self->position == 0)
        self->position = 1;
    self->rowDistance = self->posZ / self->position;
    self->floorStepX = self->rowDistance * (self->rayDirX1 - self->rayDirX0)
        / self->parent->render->width;
    self->floorStepY = self->rowDistance * (self->rayDirY1 - self->rayDirY0)
        / self->parent->render->width;
    self->floorX =
        self->parent->player->posX + self->rowDistance * self->rayDirX0;
    self->floorY =
        self->parent->player->posY + self->rowDistance * self->rayDirY0;
    self->fc_xloop(self, y);
}

void fc_xloop(TextureClass_t *self, int y)
{
    for (int x = 0; x < self->parent->render->width; x++) {
        self->cellX = (int) (self->floorX);
        self->cellY = (int) (self->floorY);
        self->tx = (int) (self->textureSize * (self->floorX - self->cellX))
            & (self->textureSize - 1);
        self->ty = (int) (self->textureSize * (self->floorY - self->cellY))
            & (self->textureSize - 1);
        self->floorX += self->floorStepX;
        self->floorY += self->floorStepY;
        self->floorColor =
            sfImage_getPixel(self->floorImage, self->tx, self->ty);
        self->ceilingColor =
            sfImage_getPixel(self->ceilingImage, self->tx, self->ty);
        self->set_fc_pixels(self, x, y);
    }
}

void set_fc_pixels(TextureClass_t *self, int x, int y)
{
    int pixelPos = (y * self->parent->render->width + x) * 4;
    int ceilingY = self->parent->render->height - y - 1;
    int ceilingPixelPos = (ceilingY * self->parent->render->width + x) * 4;

    self->buffer[pixelPos] = self->floorColor.r;
    self->buffer[pixelPos + 1] = self->floorColor.g;
    self->buffer[pixelPos + 2] = self->floorColor.b;
    self->buffer[pixelPos + 3] = self->floorColor.a;
    self->buffer[ceilingPixelPos] = self->ceilingColor.r;
    self->buffer[ceilingPixelPos + 1] = self->ceilingColor.g;
    self->buffer[ceilingPixelPos + 2] = self->ceilingColor.b;
    self->buffer[ceilingPixelPos + 3] = self->ceilingColor.a;
}
