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
    game->screenWidth = 1920;
    game->screenHeight = 1080;
    game->mode = (sfVideoMode){game->screenWidth, game->screenHeight, 32};
    game->render->window =
        sfRenderWindow_create(game->mode, "Wolf3D", sfClose, NULL);
    if (!game->render->window)
        return 84;
    game->render->width = game->screenWidth;
    game->render->height = game->screenHeight;
    game->render->zBuffer = malloc(sizeof(double) * game->screenWidth);
    if (!game->render->zBuffer)
        return 84;
    game->clock = sfClock_create();
    game->state_manager->init_state_manager(game->state_manager);
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
            if (game->state_manager->current_state == GAME_PLAYING) {
                game->state_manager->transition_to_state(
                    game->state_manager, GAME_MENU);
            } else {
                sfRenderWindow_close(game->render->window);
            }
        }
    }
    game->state_manager->handle_state_input(game->state_manager);
}

void update_game(GameClass_t *game)
{
    sfTime elapsed = sfClock_getElapsedTime(game->clock);
    listener_data_t player_pos;

    game->deltaTime = sfTime_asSeconds(elapsed);
    sfClock_restart(game->clock);
    game->state_manager->update_state(game->state_manager, game->deltaTime);
    if (game->state_manager->current_state != GAME_PLAYING)
        return;
    player_pos = (listener_data_t){game->player->posX, game->player->posY,
        game->player->dirX, game->player->dirY};
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
    game->sound->update_listener_position(game->sound, player_pos);
    game->hud->update_hud(game->hud, game->deltaTime);
    game->hud->wizard->update_sprite(game->hud->wizard, game->deltaTime);
}

void render_game(GameClass_t *game)
{
    sfRenderWindow_clear(game->render->window, sfBlack);
    if (game->state_manager->current_state == GAME_PLAYING) {
        game->texture->draw_floor_ceiling(game->texture);
        game->render->render_walls(game->render);
        game->weapon->render(game->weapon);
        game->hud->render_hud(game->hud);
    } else {
        game->state_manager->render_state(game->state_manager);
    }
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
    game->game_loop(game);
    if (game->render->zBuffer)
        free(game->render->zBuffer);
    if (game->clock)
        sfClock_destroy(game->clock);
    destroy_class(game);
    return 0;
}