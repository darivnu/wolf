/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** game
*/

#include "game.h"

const GameClass_t game_init = {
    {
        ._size = sizeof game_init,
        ._name = "GameClass_t",
    },
};

const class_t *Game = (const class_t *) &game_init;
