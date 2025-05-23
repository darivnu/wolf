/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/game.h"
#include "../inc/map.h"

int init_game_components(GameClass_t *game)
{
    game->screenWidth = 800;
    game->screenHeight = 600;
    sfVideoMode mode = {game->screenWidth, game->screenHeight, 32};
    game->render->window =
        sfRenderWindow_create(mode, "Wolf3D", sfClose, NULL);
    if (!game->render->window)
        return 84;
    game->render->width = game->screenWidth;
    game->render->height = game->screenHeight;
    game->render->zBuffer = malloc(sizeof(double) * game->screenWidth);
    if (!game->render->zBuffer)
        return 84;
    game->set_game_basic_components(game);
    game->clock = sfClock_create();
    game->weapon->init_weapon(game->weapon);
    return 0;
}

void handle_events(GameClass_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->render->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game->render->window);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
            sfRenderWindow_close(game->render->window);
        }
    }
}

void update_game(GameClass_t *game)
{
    sfTime elapsed = sfClock_getElapsedTime(game->clock);
    listener_data_t player_pos = {game->player->posX, game->player->posY,
        game->player->dirX, game->player->dirY};

    game->deltaTime = sfTime_asSeconds(elapsed);
    sfClock_restart(game->clock);
    game->input->forward = 0.0;
    game->input->strafe = 0.0;
    game->input->rotate = 0.0;
    game->input->get_input(game->input);
    game->player->player_move(game->player);
    game->player->player_rotate(game->player);
    game->animation->update_animations(game->animation, game->deltaTime);
    game->weapon->handle_input(game->weapon);
    game->weapon->update(game->weapon, game->deltaTime);
    game->sound->update_sounds(game->sound);
    game->sound->update_listener_position(game->sound, 
        player_pos);
}

void render_game(GameClass_t *game)
{
    sfRenderWindow_clear(game->render->window, sfBlack);
    game->texture->draw_floor_ceiling(game->texture);
    game->render->render_walls(game->render);
    game->weapon->render(game->weapon);
    sfRenderWindow_display(game->render->window);
}

int main(void)
{
    GameClass_t *game = new_class(Game);
    int status = 0;

    if (!game)
        return 84;

    status = game->init_game_components(game);
    if (status != 0) {
        destroy_class(game);
        return status;
    }

    // ✅ Cargar el mapa en formato plano
    map_t *raw_map = load_map("assets/maps/level1.map");
    if (!raw_map) {
        destroy_class(game);
        return 84;
    }

    // ✅ Cargar el mapa dentro de tu clase MapClass_t
    if (!game->map || !game->map->load_from_data) {
        destroy_class(game);
        return 84;
    }

    if (game->map->load_from_data(game->map, raw_map) != 0) {
        destroy_class(game);
        return 84;
    }

    // ▶️ Bucle principal del juego
    game->game_loop(game);

    // 🧹 Limpieza
    if (game->render && game->render->zBuffer)
        free(game->render->zBuffer);
    if (game->clock)
        sfClock_destroy(game->clock);
    destroy_class(game);

    return 0;
}
