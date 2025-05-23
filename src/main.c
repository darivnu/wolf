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
#include "../inc/state.h"
#include "../inc/menu.h"

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
    sfVideoMode mode = {1280, 720, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Harry Potter Wolf3D", sfClose, NULL);
    if (!window)
        return 84;

    sfRenderWindow_setFramerateLimit(window, 60);

    state_class_t *state = create_state_manager();
    if (!state)
        return 84;

    main_menu_t *menu = create_main_menu();
    if (!menu)
        return 84;

    sfEvent event;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);

            // Menú principal
            if (state->get_state(state) == GAME_MENU)
                handle_main_menu(menu, state, window, &event);

            // Aquí podrías manejar eventos de otros estados también
        }

        sfRenderWindow_clear(window, sfBlack);

        switch (state->get_state(state)) {
            case GAME_MENU:
                render_main_menu(menu, window);
                break;
        
            case GAME_PLAYING:
                // Aquí deberías poner tu bucle de juego real
                // Por ahora puedes poner una pantalla negra limpia
                break;
        
            case GAME_SETTINGS:
                // Por ahora solo un fondo, luego añadimos botón y texto
                break;
        
            case GAME_OVER:
                // Puedes hacer un fadeout o mensaje
                break;
        }
        
        
        
        sfRenderWindow_display(window);
    }

    destroy_main_menu(menu);
    destroy_state_manager(state);
    sfRenderWindow_destroy(window);
    return 0;
}
