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
    self->max_bar_width = BAR_WIDTH_MAX;
    self->current_health = 100.0f;
    self->current_mana = 100.0f;
    self->last_mana_use_time = 0.0f;
    self->mana_regen_delay = DEFAULT_MANA_REG_DELAY;
    self->mana_regen_rate = DEFAULT_MANA_REG_RATE;
    self->current_spell = SPELL_TYPE_BLUE;
}

static void destructor(void *ptr)
{
    HUDClass_t *self = (HUDClass_t *) ptr;

    if (self->health_bar)
        sfRectangleShape_destroy(self->health_bar);
    if (self->mana_bar)
        sfRectangleShape_destroy(self->mana_bar);
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


void update_hud(HUDClass_t *self, float delta_time)
{
    self->last_mana_use_time += delta_time;
    if (self->last_mana_use_time >= self->mana_regen_delay) {
        self->regenerate_mana(self, delta_time);
    }
}

void switch_spell_hud(HUDClass_t *self, spell_type_t spell_type)
{
    const char *texture_path;

    self->current_spell = spell_type;
    if (spell_type == SPELL_TYPE_BLUE) {
        texture_path = "assets/sprites/ui_blue_void.png";
    } else {
        texture_path = "assets/sprites/ui_orange_void.png";
    }
    self->stats->load_texture(self->stats, texture_path);
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
    .switch_spell_hud = switch_spell_hud,
};

const class_t *HUD = (const class_t *) &hud_init;
