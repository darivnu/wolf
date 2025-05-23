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
} game_state_e;

typedef struct state_class_s {
    game_state_e current_state;
    void (*set_state)(struct state_class_s *, game_state_e);
    game_state_e (*get_state)(struct state_class_s *);
} state_class_t;

state_class_t *create_state_manager(void);
void destroy_state_manager(state_class_t *state);

#endif
