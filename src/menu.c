/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** menu
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../inc/menu.h"
#include <unistd.h>

main_menu_t *create_main_menu(void)
{
    main_menu_t *menu = malloc(sizeof(main_menu_t));
    if (!menu)
        return NULL;

    menu->background_texture = sfTexture_createFromFile("assets/menu/background.png", NULL);
    menu->play_texture = sfTexture_createFromFile("assets/menu/play_btn.png", NULL);
    menu->settings_texture = sfTexture_createFromFile("assets/menu/settings_btn.png", NULL);
    menu->exit_texture = sfTexture_createFromFile("assets/menu/exit_btn.png", NULL);
    if (!menu->background_texture || !menu->play_texture || !menu->settings_texture || !menu->exit_texture)
        return NULL;

    menu->background_sprite = sfSprite_create();
    menu->play_button = sfSprite_create();
    menu->settings_button = sfSprite_create();
    menu->exit_button = sfSprite_create();

    sfSprite_setTexture(menu->background_sprite, menu->background_texture, sfTrue);
    sfSprite_setTexture(menu->play_button, menu->play_texture, sfTrue);
    sfSprite_setTexture(menu->settings_button, menu->settings_texture, sfTrue);
    sfSprite_setTexture(menu->exit_button, menu->exit_texture, sfTrue);

    sfVector2f scale = {0.4f, 0.4f};
    sfSprite_setScale(menu->play_button, scale);
    sfSprite_setScale(menu->settings_button, scale);
    sfSprite_setScale(menu->exit_button, scale); 
    
    float button_width = 300;
    float button_height = 100;
    float spacing = 70;

    float start_y = (720 - (3 * button_height + 2 * spacing)) / 2.f - 130;
    float center_x = (1200 - button_width) / 2.f;

    menu->play_pos = (sfVector2f){center_x, start_y};
    menu->settings_pos = (sfVector2f){center_x, start_y + button_height + spacing};
    menu->exit_pos = (sfVector2f){center_x, start_y + 2 * (button_height + spacing)};

    sfSprite_setPosition(menu->play_button, menu->play_pos);
    sfSprite_setPosition(menu->settings_button, menu->settings_pos);
    sfSprite_setPosition(menu->exit_button, menu->exit_pos);

    return menu;
}

void handle_main_menu(main_menu_t *menu, state_class_t *state, sfRenderWindow *win, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed && event->mouseButton.button == sfMouseLeft) {
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
