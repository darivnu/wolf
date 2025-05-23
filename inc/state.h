/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** state
*/

#ifndef INCLUDED_STATE_H
    #define INCLUDED_STATE_H

typedef enum {
    GAME_MENU,
    GAME_SETTINGS,
    GAME_PLAYING,
    GAME_OVER
} game_state_t;

typedef struct StateClass_t {
    game_state_t current;
    void (*set_state)(struct StateClass_t *, game_state_t);
    game_state_t (*get_state)(struct StateClass_t *);
} StateClass_t;

StateClass_t *create_state_manager(void);
void destroy_state_manager(StateClass_t *state);

#endif
    