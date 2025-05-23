/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** create_main_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <unistd.h>
#include "../inc/menu.h"

static int load_menu_textures(main_menu_t *menu)
{
    menu->background_texture =
        sfTexture_createFromFile("assets/menu/background.png", NULL);
    menu->play_texture =
        sfTexture_createFromFile("assets/menu/play_btn.png", NULL);
    menu->settings_texture =
        sfTexture_createFromFile("assets/menu/settings_btn.png", NULL);
    menu->exit_texture =
        sfTexture_createFromFile("assets/menu/exit_btn.png", NULL);
    if (!menu->background_texture || !menu->play_texture
        || !menu->settings_texture || !menu->exit_texture)
        return 84;
    return 0;
}

static void create_menu_sprites(main_menu_t *menu)
{
    menu->background_sprite = sfSprite_create();
    menu->play_button = sfSprite_create();
    menu->settings_button = sfSprite_create();
    menu->exit_button = sfSprite_create();
    sfSprite_setTexture(
        menu->background_sprite, menu->background_texture, sfTrue);
    sfSprite_setTexture(menu->play_button, menu->play_texture, sfTrue);
    sfSprite_setTexture(menu->settings_button, menu->settings_texture, sfTrue);
    sfSprite_setTexture(menu->exit_button, menu->exit_texture, sfTrue);
}

static void set_menu_positions(main_menu_t *menu)
{
    sfVector2f scale = {0.33f, 0.33f};
    float button_width = 300 * scale.x;
    float button_height = 100 * scale.y;
    float spacing = 100;
    float start_y = (720 - (3 * button_height + 2 * spacing)) / 2.f - 130;
    float center_x = (1200 - button_width) / 2.f;

    menu->play_pos = (sfVector2f){center_x, start_y};
    menu->settings_pos =
        (sfVector2f){center_x, start_y + button_height + spacing};
    menu->exit_pos =
        (sfVector2f){center_x, start_y + 2 * (button_height + spacing)};
    sfSprite_setScale(menu->play_button, scale);
    sfSprite_setScale(menu->settings_button, scale);
    sfSprite_setScale(menu->exit_button, scale);
    sfSprite_setPosition(menu->play_button, menu->play_pos);
    sfSprite_setPosition(menu->settings_button, menu->settings_pos);
    sfSprite_setPosition(menu->exit_button, menu->exit_pos);
}

main_menu_t *create_main_menu(void)
{
    main_menu_t *menu = malloc(sizeof(main_menu_t));

    if (!menu)
        return NULL;
    if (load_menu_textures(menu) == 84)
        return NULL;
    create_menu_sprites(menu);
    set_menu_positions(menu);
    return menu;
}
