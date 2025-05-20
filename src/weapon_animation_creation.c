/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** weapon_animation_creation
*/

#include "game.h"

void create_idle_animation(
    WeaponClass_t *self, int frame_width, int frame_height)
{
    animation_data_t *wand_idle;

    wand_idle = self->parent->animation->create_animation(
        self->parent->animation, "wand_idle", ANIM_LOOP);
    self->parent->animation->add_frame(self->parent->animation, wand_idle,
        0.15f, (sfIntRect){-40, 0, frame_width, frame_height});
    self->parent->animation->add_frame(self->parent->animation, wand_idle,
        0.15f, (sfIntRect){frame_width - 40, 0, frame_width, frame_height});
    self->parent->animation->add_frame(self->parent->animation, wand_idle,
        0.15f,
        (sfIntRect){frame_width * 2 - 40, 0, frame_width, frame_height});
    self->parent->animation->add_frame(self->parent->animation, wand_idle,
        0.15f,
        (sfIntRect){frame_width * 3 - 40, 0, frame_width, frame_height});
}

void create_fire_animation(
    WeaponClass_t *self, int frame_width, int frame_height)
{
    animation_data_t *wand_fire;

    wand_fire = self->parent->animation->create_animation(
        self->parent->animation, "wand_fire", ANIM_ONCE);
    self->parent->animation->add_frame(self->parent->animation, wand_fire,
        0.1f, (sfIntRect){-40, 682, 280, frame_height});
    self->parent->animation->add_frame(self->parent->animation, wand_fire,
        0.1f, (sfIntRect){256 - 40, 682, 280, frame_height});
    self->parent->animation->add_frame(self->parent->animation, wand_fire,
        0.1f, (sfIntRect){512 - 40, 682, 280, frame_height});
    self->parent->animation->add_frame(self->parent->animation, wand_fire,
        0.1f, (sfIntRect){768 - 40, 682, 280, frame_height});
}

void setup_weapon_sprite(WeaponClass_t *self, int frame_height)
{
    animation_data_t *wand_idle;

    wand_idle = self->parent->animation->get_animation(
        self->parent->animation, "wand_idle");
    self->sprite->set_position(self->sprite, self->parent->screenWidth / 6,
        self->parent->screenHeight - frame_height * 1.2);
    self->sprite->set_scale(self->sprite, 1.2f, 1.2f);
    self->sprite->set_animation(self->sprite, wand_idle);
    self->sprite->set_visible(self->sprite, 1);
    self->parent->animation->play_animation(
        self->parent->animation, "wand_idle");
}

void load_weapon_animations(WeaponClass_t *self)
{
    const int frame_width = 256;
    const int frame_height = 256;
    const char *spritesheet_path = "assets/sprites/wandsprite.png";

    self->sprite->load_texture(self->sprite, spritesheet_path);
    self->create_idle_animation(self, frame_width, frame_height);
    self->create_fire_animation(self, frame_width, frame_height);
    self->setup_weapon_sprite(self, frame_height);
}

void handle_idle_state(WeaponClass_t *self, animation_data_t *idle_anim,
    animation_data_t *fire_anim)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        self->parent->animation->stop_animation(
            self->parent->animation, "wand_idle");
        self->parent->animation->reset_animation(
            self->parent->animation, "wand_fire");
        self->parent->animation->play_animation(
            self->parent->animation, "wand_fire");
        self->sprite->set_animation(self->sprite, fire_anim);
        self->state = WEAPON_STATE_FIRING;
    }
}
