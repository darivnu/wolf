/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** game
*/

#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    GameClass_t *self = (GameClass_t *) ptr;

    self->ray = new_class(Ray, self);
    self->player = new_class(Player, self);
    self->map = new_class(Map, self);
    self->render = new_class(Render, self);
    self->input = new_class(Input, self);
    self->texture = new_class(Texture, self);
    self->animation = new_class(Animation, self);
    self->sprite = new_class(Sprite, self);
}

static void destructor(void *ptr)
{
    GameClass_t *self = (GameClass_t *) ptr;

    destroy_class(self->ray);
    destroy_class(self->player);
    destroy_class(self->map);
    destroy_class(self->render);
    destroy_class(self->input);
    destroy_class(self->texture);
    destroy_class(self->animation);
    destroy_class(self->sprite);
}

const GameClass_t game_init = {
    {
        ._size = sizeof game_init,
        ._name = "GameClass_t",
        ._constructor = constructor,
        ._destructor = destructor,
    },
    .init_game_components = init_game_components,
    .handle_events = handle_events,
    .update_game = update_game,
    .render_game = render_game,
};

const class_t *Game = (const class_t *) &game_init;
