/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sound_3d
*/

#include "game.h"

void set_sound_3d_position(
    SoundClass_t *self, const char *name, sound_position_t pos)
{
    sound_effect_t *effect;

    effect = self->get_sound(self, name);
    if (!effect || !effect->sound)
        return;
    effect->is_3d = 1;
    sfSound_setPosition(effect->sound, (sfVector3f){pos.x, pos.y, pos.z});
    sfSound_setMinDistance(effect->sound, effect->min_distance);
    sfSound_setAttenuation(effect->sound, effect->attenuation);
}

void update_listener_position(SoundClass_t *self, listener_data_t data)
{
    sfVector3f position;
    sfVector3f direction;

    position = (sfVector3f){data.x, data.y, 0.0f};
    direction = (sfVector3f){data.dirX, data.dirY, 0.0f};
    sfListener_setPosition(position);
    sfListener_setDirection(direction);
}
