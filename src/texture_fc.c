/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** texture_fc
*/

#include "../inc/game.h"

void draw_floor_ceiling(TextureClass_t *self)
{
    self->floorImage = sfTexture_copyToImage(self->floorTexture);
    self->ceilingImage = sfTexture_copyToImage(self->ceilingTexture);
    if (!self->floorImage || !self->ceilingImage) {
        if (self->floorImage)
            sfImage_destroy(self->floorImage);
        if (self->ceilingImage)
            sfImage_destroy(self->ceilingImage);
        return;
    }
    self->buffer =
        malloc(self->parent->render->width * self->parent->render->height * 4);
    if (!self->buffer) {
        sfImage_destroy(self->floorImage);
        sfImage_destroy(self->ceilingImage);
        return;
    }
    self->fc_logic(self);
}

void fc_logic(TextureClass_t *self)
{
    self->set_fc(self);
    for (int y = self->parent->render->height / 2;
        y < self->parent->render->height; y++) {
        self->fc_loop(self, y);
    }
    sfImage_destroy(self->floorImage);
    sfImage_destroy(self->ceilingImage);
    self->fcImage = sfImage_createFromPixels(self->parent->render->width,
        self->parent->render->height, self->buffer);
    self->fcTexture = sfTexture_createFromImage(self->fcImage, NULL);
    self->fcSprite = sfSprite_create();
    sfSprite_setTexture(self->fcSprite, self->fcTexture, sfTrue);
    sfRenderWindow_drawSprite(
        self->parent->render->window, self->fcSprite, NULL);
    sfSprite_destroy(self->fcSprite);
    sfTexture_destroy(self->fcTexture);
    sfImage_destroy(self->fcImage);
    free(self->buffer);
}
