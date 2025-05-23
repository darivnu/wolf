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
    self->weapon = new_class(Weapon, self);
    self->sound = new_class(Sound, self);
    self->hud = new_class(HUD, self);
}

void set_game_basic_components(GameClass_t *game)
{
    int result = 0;

    result =
        game->map->map_load_from_file(game->map, "assets/maps/level1.txt");
    if (result != 0) {
        printf("Error loading map\n");
        exit(84);
    }
    game->player->posX = 5.0;
    game->player->posY = 5.0;
    game->player->dirX = 1.0;
    game->player->dirY = 0.0;
    game->player->init_player(game->player);
    game->init_sound(game);
}

void game_loop(GameClass_t *game)
{
    while (sfRenderWindow_isOpen(game->render->window)) {
        handle_events(game);
        update_game(game);
        render_game(game);
    }
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
    destroy_class(self->weapon);
    destroy_class(self->sound);
    destroy_class(self->hud);
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
    .set_game_basic_components = set_game_basic_components,
    .game_loop = game_loop,
    .init_sound = init_sound,
};

const class_t *Game = (const class_t *) &game_init;
