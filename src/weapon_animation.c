/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** weapon_animation
*/

#include "game.h"
#include "weapon.h"

void handle_firing_state(WeaponClass_t *self, animation_data_t *fire_anim)
{
    if (fire_anim->current_frame >= fire_anim->frame_count - 1 &&
        !fire_anim->is_playing) {
        self->state = WEAPON_STATE_TRANSITIONING;
        self->transition_timer = 0.04f;
    }
}

void handle_transition_state(WeaponClass_t *self, animation_data_t *idle_anim)
{
    self->transition_timer -= self->parent->deltaTime;
    if (self->transition_timer <= 0.0f) {
        self->parent->animation->reset_animation(
            self->parent->animation, "wand_idle");
        self->parent->animation->play_animation(
            self->parent->animation, "wand_idle");
        self->weapon_sprite->set_animation(self->weapon_sprite, idle_anim);
        self->state = WEAPON_STATE_IDLE;
    }
}

static void handle_weapon_switch(WeaponClass_t *self, animation_data_t *idle_anim, animation_data_t *fire_anim)
{
switch (self->state) {
        case WEAPON_STATE_IDLE:
            self->handle_idle_state(self, idle_anim, fire_anim);
            break;
        case WEAPON_STATE_FIRING:
            self->handle_firing_state(self, fire_anim);
            break;
        case WEAPON_STATE_TRANSITIONING:
            self->handle_transition_state(self, idle_anim);
            break;
    }
}

void handle_weapon_input(WeaponClass_t *self)
{
    animation_data_t *idle_anim;
    animation_data_t *fire_anim;

    idle_anim = self->parent->animation->get_animation(
        self->parent->animation, "wand_idle");
    fire_anim = self->parent->animation->get_animation(
        self->parent->animation, "wand_fire");
    if (!idle_anim || !fire_anim)
        return;
    self->handle_spell_switch(self);
    handle_weapon_switch(self, idle_anim, fire_anim);
}

void update_weapon(WeaponClass_t *self, float delta_time)
{
    if (!self->weapon_sprite)
        return;
    self->weapon_sprite->update_sprite(self->weapon_sprite, delta_time);
}

void render_weapon(WeaponClass_t *self)
{
    if (!self->weapon_sprite)
        return;
    self->weapon_sprite->draw_sprite(self->weapon_sprite);
}
