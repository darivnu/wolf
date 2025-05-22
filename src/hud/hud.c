/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** hud
*/

#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    HUDClass_t *self = (HUDClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
}

void init_hud(HUDClass_t *self)
{
    self->stats = new_class(Sprite, self->parent);
    self->stats->load_texture(self->stats, "assets/sprites/ui_blue_full.png");
    self->stats->set_position(self->stats, -20.0f, -115.0f);
    self->stats->set_scale(self->stats, 0.4f, 0.4f);
    self->stats->set_visible(self->stats, 1);
}

const HUDClass_t hud_init = {
    {
        ._size = sizeof hud_init,
        ._name = "HUDClass_t",
        ._constructor = constructor,
    },
    .init_hud = init_hud,
};

const class_t *HUD = (const class_t *) &hud_init;
