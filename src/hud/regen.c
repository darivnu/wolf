/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** regen
*/

#include "game.h"

void use_mana(HUDClass_t *self, float amount)
{
    float new_mana;

    new_mana = self->current_mana - amount;
    self->update_mana_bar(self, new_mana);
    self->last_mana_use_time = 0.0f;
}

void regenerate_mana(HUDClass_t *self, float delta_time)
{
    float regen_amount;
    float new_mana;

    if (self->current_mana >= 100.0f)
        return;
    regen_amount = self->mana_regen_rate * delta_time;
    new_mana = self->current_mana + regen_amount;
    self->update_mana_bar(self, new_mana);
}
