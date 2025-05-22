/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** hud
*/

#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Vector2.h>
#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    HUDClass_t *self = (HUDClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
    self->health_bar = NULL;
    self->mana_bar = NULL;
    self->max_bar_width = 123.0f;
    self->current_health = 100.0f;
    self->current_mana = 100.0f;
    self->last_mana_use_time = 0.0f;
    self->mana_regen_delay = 4.0f;
    self->mana_regen_rate = 20.0f;
}

void init_hud(HUDClass_t *self)
{
    self->stats = new_class(Sprite, self->parent);
    self->stats->load_texture(self->stats, "assets/sprites/ui_blue_void.png");
    self->stats->set_position(self->stats, -20.0f, -115.0f);
    self->stats->set_scale(self->stats, 0.4f, 0.4f);
    self->stats->set_visible(self->stats, 1);
    self->create_health_bar(self);
    self->create_mana_bar(self);
}

static void destructor(void *ptr)
{
    HUDClass_t *self = (HUDClass_t *) ptr;

    if (self->health_bar)
        sfRectangleShape_destroy(self->health_bar);
    if (self->mana_bar)
        sfRectangleShape_destroy(self->mana_bar);
}

void update_hud(HUDClass_t *self, float delta_time)
{
    self->last_mana_use_time += delta_time;
    if (self->last_mana_use_time >= self->mana_regen_delay) {
        self->regenerate_mana(self, delta_time);
    }
}

const HUDClass_t hud_init = {
    {
        ._size = sizeof hud_init,
        ._name = "HUDClass_t",
        ._constructor = constructor,
        ._destructor = destructor,
    },
    .init_hud = init_hud,
    .render_hud = render_hud,
    .create_health_bar = create_health_bar,
    .create_mana_bar = create_mana_bar,
    .update_health_bar = update_health_bar,
    .update_mana_bar = update_mana_bar,
    .update_hud = update_hud,
    .use_mana = use_mana,
    .regenerate_mana = regenerate_mana,
};

const class_t *HUD = (const class_t *) &hud_init;