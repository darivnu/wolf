/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** state
*/
#include <stdlib.h>
#include "../inc/state.h"

static void set_game_state(StateClass_t *state, game_state_t new_state)
{
    if (state)
        state->current = new_state;
}

static game_state_t get_game_state(StateClass_t *state)
{
    if (!state)
        return GAME_MENU;
    return state->current;
}

StateClass_t *create_state_manager(void)
{
    StateClass_t *state = malloc(sizeof(StateClass_t));
    if (!state)
        return NULL;
    state->current = GAME_MENU;
    state->set_state = &set_game_state;
    state->get_state = &get_game_state;
    return state;
}

void destroy_state_manager(StateClass_t *state)
{
    if (state)
        free(state);
}
