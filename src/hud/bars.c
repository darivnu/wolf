/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** bars
*/

#include "game.h"

void create_health_bar(HUDClass_t *self)
{
    self->health_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(self->health_bar,
        (sfVector2f){self->max_bar_width, 18});
    sfRectangleShape_setPosition(self->health_bar, (sfVector2f){223, 30});
    sfRectangleShape_setFillColor(self->health_bar, sfRed);
}

void create_mana_bar(HUDClass_t *self)
{
    self->mana_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(self->mana_bar,
        (sfVector2f){self->max_bar_width, 18});
    sfRectangleShape_setPosition(self->mana_bar, (sfVector2f){223, 62});
    sfRectangleShape_setFillColor(self->mana_bar, sfBlue);
}

void render_hud(HUDClass_t *self)
{
    self->stats->draw_sprite(self->stats);
    if (self->health_bar)
        sfRenderWindow_drawRectangleShape(self->parent->render->window,
            self->health_bar, NULL);
    if (self->mana_bar)
        sfRenderWindow_drawRectangleShape(self->parent->render->window,
            self->mana_bar, NULL);
}

void update_health_bar(HUDClass_t *self, float percentage)
{
    float new_width;

    if (!self->health_bar)
        return;
    if (percentage < 0.0f)
        percentage = 0.0f;
    if (percentage > 100.0f)
        percentage = 100.0f;
    self->current_health = percentage;
    new_width = (self->max_bar_width * percentage) / 100.0f;
    sfRectangleShape_setSize(self->health_bar, (sfVector2f){new_width, 18});
}

void update_mana_bar(HUDClass_t *self, float percentage)
{
    float new_width;

    if (!self->mana_bar)
        return;
    if (percentage < 0.0f)
        percentage = 0.0f;
    if (percentage > 100.0f)
        percentage = 100.0f;
    self->current_mana = percentage;
    new_width = (self->max_bar_width * percentage) / 100.0f;
    sfRectangleShape_setSize(self->mana_bar, (sfVector2f){new_width, 18});
}

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