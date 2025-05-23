/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** weapon
*/

#include "weapon.h"
#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    WeaponClass_t *self = (WeaponClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
    self->weapon_sprite = NULL;
    self->state = WEAPON_STATE_IDLE;
    self->current_spell = SPELL_TYPE_BLUE;
    self->transition_timer = 0.0f;
}

static void destructor(void *ptr)
{
    WeaponClass_t *self = (WeaponClass_t *) ptr;

    if (self->weapon_sprite)
        destroy_class(self->weapon_sprite);
}

void init_weapon(WeaponClass_t *self)
{
    self->weapon_sprite = new_class(Sprite, self->parent);
    if (!self->weapon_sprite)
        return;
    self->load_animations(self);
}

const WeaponClass_t weapon_init = {
    {
        ._size = sizeof weapon_init,
        ._name = "WeaponClass_t",
        ._constructor = constructor,
        ._destructor = destructor,
    },
    .init_weapon = init_weapon,
    .load_animations = load_weapon_animations,
    .create_idle_animation = create_idle_animation,
    .create_fire_animation = create_fire_animation,
    .setup_weapon_sprite = setup_weapon_sprite,
    .update = update_weapon,
    .handle_input = handle_weapon_input,
    .handle_idle_state = handle_idle_state,
    .handle_firing_state = handle_firing_state,
    .handle_transition_state = handle_transition_state,
    .render = render_weapon,
    .switch_spell = switch_spell,
    .handle_spell_switch = handle_spell_switch,
};

const class_t *Weapon = (const class_t *) &weapon_init;
