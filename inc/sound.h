/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** sound
*/

#include <SFML/Audio.h>
#include "oop.h"

#ifndef INCLUDED_SOUND_H
    #define INCLUDED_SOUND_H

typedef struct game_aux GameClass_t;
typedef struct sound_aux SoundClass_t;
typedef struct sound_effect sound_effect_t;
typedef struct sound_music sound_music_t;

typedef enum {
    SOUND_ONCE,
    SOUND_LOOP,
    SOUND_REPEAT,
} sound_play_mode_t;

typedef struct {
    float x;
    float y;
    float z;
} sound_position_t;

typedef struct {
    float x;
    float y;
    float dirX;
    float dirY;
} listener_data_t;

typedef struct sound_effect {
    char *name;
    sfSound *sound;
    sfSoundBuffer *buffer;
    float volume;
    float pitch;
    float min_distance;
    float attenuation;
    sound_play_mode_t mode;
    int is_playing;
    int is_3d;
} sound_effect_t;

typedef struct sound_music {
    char *name;
    sfMusic *music;
    float volume;
    sound_play_mode_t mode;
    int is_playing;
} sound_music_t;

typedef struct sound_aux {
    /* class metadata */
    class_t meta;
    /* class members */
    GameClass_t *parent;
    sound_effect_t **effects;
    sound_music_t **music;
    int effect_count;
    int music_count;
    float master_volume;
    float effect_volume;
    float music_volume;
    /* class methods */
    sound_effect_t *(*create_sound_effect)(
        SoundClass_t *, const char *, const char *);
    sound_music_t *(*create_music)(SoundClass_t *, const char *, const char *);
    void (*play_sound)(SoundClass_t *, const char *);
    void (*play_music)(SoundClass_t *, const char *);
    void (*stop_sound)(SoundClass_t *, const char *);
    void (*stop_music)(SoundClass_t *, const char *);
    void (*pause_sound)(SoundClass_t *, const char *);
    void (*pause_music)(SoundClass_t *, const char *);
    void (*set_sound_volume)(SoundClass_t *, const char *, float);
    void (*set_music_volume)(SoundClass_t *, const char *, float);
    void (*set_master_volume)(SoundClass_t *, float);
    void (*set_effect_volume)(SoundClass_t *, float);
    void (*set_music_volume_global)(SoundClass_t *, float);
    void (*set_sound_3d_position)(
        SoundClass_t *, const char *, sound_position_t);
    void (*update_listener_position)(SoundClass_t *, listener_data_t);
    sound_effect_t *(*get_sound)(SoundClass_t *, const char *);
    sound_music_t *(*get_music)(SoundClass_t *, const char *);
    void (*update_sounds)(SoundClass_t *);
    void (*update_sounds_effect)(SoundClass_t *, int, sfSoundStatus);
    void (*update_sounds_music)(SoundClass_t *, int, sfSoundStatus);
    void (*cleanup_sounds)(SoundClass_t *);
    sound_effect_t *(*allocate_effect_memory)(SoundClass_t *, const char *);
    int (*setup_sound_buffer)(sound_effect_t *, const char *);
} SoundClass_t;

sound_effect_t *create_sound_effect(
    SoundClass_t *, const char *, const char *);
sound_music_t *create_music(SoundClass_t *, const char *, const char *);
void play_sound(SoundClass_t *, const char *);
void play_music(SoundClass_t *, const char *);
void stop_sound(SoundClass_t *, const char *);
void stop_music(SoundClass_t *, const char *);
void pause_sound(SoundClass_t *, const char *);
void pause_music(SoundClass_t *, const char *);
void set_sound_volume(SoundClass_t *, const char *, float);
void set_music_volume(SoundClass_t *, const char *, float);
void set_master_volume(SoundClass_t *, float);
void set_effect_volume(SoundClass_t *, float);
void set_music_volume_global(SoundClass_t *, float);
void set_sound_3d_position(SoundClass_t *, const char *, sound_position_t);
void update_listener_position(SoundClass_t *, listener_data_t);
sound_effect_t *get_sound(SoundClass_t *, const char *);
sound_music_t *get_music(SoundClass_t *, const char *);
void update_sounds(SoundClass_t *);
void update_sounds_effect(SoundClass_t *, int, sfSoundStatus);
void update_sounds_music(SoundClass_t *, int, sfSoundStatus);
void cleanup_sounds(SoundClass_t *);
sound_effect_t *allocate_effect_memory(SoundClass_t *, const char *);
int setup_sound_buffer(sound_effect_t *, const char *);

void init_sound_effect(sound_effect_t *, const char *);
void init_music(sound_music_t *, const char *);

extern const class_t *Sound;

#endif
