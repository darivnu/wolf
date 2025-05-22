/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** spells
*/

#include "game.h"

void switch_spell(WeaponClass_t *self, spell_type_t spell_type)
{
    const char *sprite_path;

    self->current_spell = spell_type;
    if (spell_type == SPELL_TYPE_BLUE) {
        sprite_path = "assets/sprites/wandsprite_blue.png";
    } else {
        sprite_path = "assets/sprites/wandsprite_orange.png";
    }
    self->weapon_sprite->load_texture(self->weapon_sprite, sprite_path);
    self->parent->hud->switch_spell_hud(self->parent->hud, spell_type);
}

void handle_spell_switch(WeaponClass_t *self)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1)) {
        if (self->current_spell != SPELL_TYPE_BLUE)
            self->switch_spell(self, SPELL_TYPE_BLUE);
    }
    if (sfKeyboard_isKeyPressed(sfKeyNum2)) {
        if (self->current_spell != SPELL_TYPE_ORANGE)
            self->switch_spell(self, SPELL_TYPE_ORANGE);
    }
}

