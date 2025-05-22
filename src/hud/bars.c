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
