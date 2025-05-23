/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** menu
*/

#ifndef INCLUDED_MENU_H
    #define INCLUDED_MENU_H

    #include <SFML/Graphics.h>
    #include "state.h"

typedef struct main_menu_s {
    sfSprite *play_button;
    sfSprite *settings_button;
    sfSprite *exit_button;
    sfTexture *play_texture;
    sfTexture *settings_texture;
    sfTexture *exit_texture;

    sfVector2f play_pos;
    sfVector2f settings_pos;
    sfVector2f exit_pos;

    sfSprite *background_sprite;
    sfTexture *background_texture;
} main_menu_t;

main_menu_t *create_main_menu(void);
void handle_main_menu(main_menu_t *menu, state_class_t *state, sfRenderWindow *win, sfEvent *event);
void render_main_menu(main_menu_t *menu, sfRenderWindow *win);
void destroy_main_menu(main_menu_t *menu);

#endif
