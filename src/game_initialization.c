/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** game_initialization
*/

#include <string.h>
#include "game.h"

void init_sound_effect(sound_effect_t *effect, const char *name)
{
    effect->name = strdup(name);
    effect->sound = NULL;
    effect->buffer = NULL;
    effect->volume = 1.0f;
    effect->pitch = 1.0f;
    effect->min_distance = 200.0f;
    effect->attenuation = 10.0f;
    effect->mode = SOUND_ONCE;
    effect->is_playing = 0;
    effect->is_3d = 0;
}

void init_sound(GameClass_t *game)
{
    game->sound->create_music(
        game->sound, "background", "assets/music/music1.mp3");
    game->sound->create_sound_effect(
        game->sound, "footstep", "assets/sounds/footsteps.mp3");
    game->sound->create_sound_effect(
        game->sound, "weapon_fire_blue", "assets/sounds/blue_spell1.wav");
    game->sound->create_sound_effect(
        game->sound, "weapon_fire_orange", "assets/sounds/orange_spell1.wav");
    game->sound->set_music_volume(game->sound, "background", 8.5f);
    game->sound->set_effect_volume(game->sound, 8.5f);
    game->sound->play_music(game->sound, "background");
}
