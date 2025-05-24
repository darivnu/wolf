/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** wizard_port
*/

#include <SFML/Graphics/Rect.h>
#include "game.h"

// self->wizard = new_class(Sprite, self->parent);
// self->wizard->load_texture(self->wizard,
// "assets/textures/wizard_iddle2.png");

void set_wizard_portrait_anim(HUDClass_t *self)
{
    self->wizard_animation = self->parent->animation->create_animation(
        self->parent->animation, "wizard_idle", ANIM_PINGPONG);
    self->parent->animation->add_frame(self->parent->animation,
        self->wizard_animation, 0.15f, (sfIntRect){64, 0, 64, 80});
}

void set_wizard_portrait_sprite(HUDClass_t *self)
{
    self->wizard = new_class(Sprite, self->parent);
    self->wizard->load_texture(self->wizard, "assets/sprites/wizard_female.png");
    self->wizard->set_position(self->wizard, -0.0f, -10.0f);
    self->wizard->set_scale(self->wizard, 0.13f, 0.13f);
    self->wizard->set_visible(self->wizard, 1);
}
