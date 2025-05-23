/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** state
*/

#include <stdlib.h>
#include "../inc/state.h"

static void set_game_state(state_class_t *state, game_state_e new_state)
{
    if (state)
        state->current_state = new_state;
}

static game_state_e get_game_state(state_class_t *state)
{
    return state ? state->current_state : GAME_MENU;
}

state_class_t *create_state_manager(void)
{
    state_class_t *manager = malloc(sizeof(state_class_t));
    if (!manager)
        return NULL;
    manager->current_state = GAME_MENU;
    manager->set_state = &set_game_state;
    manager->get_state = &get_game_state;
    return manager;
}

void destroy_state_manager(state_class_t *state)
{
    if (state)
        free(state);
}
