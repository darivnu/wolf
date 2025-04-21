/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** texture
*/

#include <SFML/Config.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    TextureClass_t *self = (TextureClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
    self->load_textures(self);
}

void load_textures(TextureClass_t *self)
{
    self->wallTextures = malloc(sizeof(sfTexture *) * NUM_TEXTURES);
    self->floorTexture =
        sfTexture_createFromFile("assets/textures/str_stoneflr1.png", NULL);
    self->ceilingTexture =
        sfTexture_createFromFile("assets/textures/str_stonegen1.png", NULL);
    self->wallTextures[0] =
        sfTexture_createFromFile("assets/textures/str_stonebrk1.png", NULL);
    self->wallTextures[1] =
        sfTexture_createFromFile("assets/textures/str_metalflr1.png", NULL);
    self->wallTextures[2] =
        sfTexture_createFromFile("assets/textures/str_metalpan8.png", NULL);
    self->wallSprite = sfSprite_create();
    self->textureSize = 256;
}

void draw_textured_wall(TextureClass_t *self, int x)
{
    self->texNum = self->parent->ray->wallType - 1;
    self->textureRect.left = self->parent->ray->texX;
    self->textureRect.top = 0;
    self->textureRect.width = 1;
    self->textureRect.height = self->textureSize;
    sfSprite_setTexture(
        self->wallSprite, self->wallTextures[self->texNum], sfFalse);
    sfSprite_setTextureRect(self->wallSprite, self->textureRect);
    self->wallHeight =
        self->parent->render->height / self->parent->ray->perpWallDist;
    sfSprite_setScale(self->wallSprite,
        (sfVector2f){1.0f, self->wallHeight / self->textureSize});
    self->posY = (self->parent->render->height - self->wallHeight) / 2.0f;
    sfSprite_setPosition(self->wallSprite, (sfVector2f){x, self->posY});
    sfRenderWindow_drawSprite(
        self->parent->render->window, self->wallSprite, NULL);
}

const TextureClass_t texture_init = {
    {
        ._size = sizeof texture_init,
        ._name = "TextureClass_t",
        ._constructor = constructor,
    },
    .load_textures = load_textures,
    .draw_textured_wall = draw_textured_wall,
    .draw_floor_ceiling = draw_floor_ceiling,
    .set_fc = set_fc,
    .set_fc_pixels = set_fc_pixels,
    .fc_loop = fc_loop,
    .fc_xloop = fc_xloop,
    .fc_logic = fc_logic,
};

const class_t *Texture = (class_t *) &texture_init;
