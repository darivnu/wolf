/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** menu
*/

#include "../inc/menu.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <unistd.h>

void handle_main_menu(main_menu_t *menu, StateClass_t *state,
    sfRenderWindow *win, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
        sfFloatRect exit = sfSprite_getGlobalBounds(menu->exit_button);
        sfFloatRect settings = sfSprite_getGlobalBounds(menu->settings_button);
        sfFloatRect play = sfSprite_getGlobalBounds(menu->play_button);

        if (sfFloatRect_contains(&exit, mouse.x, mouse.y)) {
            sfRenderWindow_close(win);
        } else if (sfFloatRect_contains(&settings, mouse.x, mouse.y)) {
            state->set_state(state, GAME_SETTINGS);
        } else if (sfFloatRect_contains(&play, mouse.x, mouse.y)) {
            state->set_state(state, GAME_PLAYING);
        }
    }
}

void render_main_menu(main_menu_t *menu, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, menu->background_sprite, NULL);
    sfRenderWindow_drawSprite(win, menu->play_button, NULL);
    sfRenderWindow_drawSprite(win, menu->settings_button, NULL);
    sfRenderWindow_drawSprite(win, menu->exit_button, NULL);
}

void destroy_main_menu(main_menu_t *menu)
{
    if (!menu)
        return;
    sfSprite_destroy(menu->play_button);
    sfSprite_destroy(menu->settings_button);
    sfSprite_destroy(menu->exit_button);
    sfSprite_destroy(menu->background_sprite);

    sfTexture_destroy(menu->play_texture);
    sfTexture_destroy(menu->settings_texture);
    sfTexture_destroy(menu->exit_texture);
    sfTexture_destroy(menu->background_texture);

    free(menu);
}
