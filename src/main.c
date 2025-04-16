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
#include "game.h"

int init_game_components(GameClass_t *game)
{
    game->screenWidth = 800;
    game->screenHeight = 600;
    sfVideoMode mode = {game->screenWidth, game->screenHeight, 32};
    game->render->window = sfRenderWindow_create(mode, "Wolf3D", sfClose, NULL);
    if (!game->render->window)
        return 84;
    game->render->width = game->screenWidth;
    game->render->height = game->screenHeight;
    game->render->zBuffer = malloc(sizeof(double) * game->screenWidth);
    if (!game->render->zBuffer)
        return 84;
    game->map->map_create(game->map, 10, 10);
    game->player->posX = 5.0;
    game->player->posY = 5.0;
    game->player->dirX = 1.0;
    game->player->dirY = 0.0;
    game->player->init_player(game->player);
    game->clock = sfClock_create();
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
    game->deltaTime = sfTime_asSeconds(elapsed);
    sfClock_restart(game->clock);
    game->input->forward = 0.0;
    game->input->strafe = 0.0;
    game->input->rotate = 0.0;
    game->input->get_input(game->input);
    game->player->player_move(game->player);
    game->player->player_rotate(game->player);
}

void render_game(GameClass_t *game)
{
    sfRenderWindow_clear(game->render->window, sfBlack);
    game->render->render_walls(game->render);
    sfRenderWindow_display(game->render->window);
}

int main(void)
{
    GameClass_t *game = new_class(Game);
    int status = 0;
    
    if (!game) {
        return 84;
    }
    status = init_game_components(game);
    if (status != 0) {
        destroy_class(game);
        return status;
    }
    while (sfRenderWindow_isOpen(game->render->window)) {
        handle_events(game);
        update_game(game);
        render_game(game);
    }
    if (game->render->zBuffer)
        free(game->render->zBuffer);
    if (game->clock)
        sfClock_destroy(game->clock);
    destroy_class(game);
    return 0;
}