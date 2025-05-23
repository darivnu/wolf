/*
** EPITECH PROJECT, 2025
** wolf
** File description:
** input
*/

#include <SFML/Config.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Window.h>
#include "game.h"

static void constructor(void *ptr, va_list *args)
{
    InputClass_t *self = (InputClass_t *) ptr;

    self->parent = va_arg(*args, GameClass_t *);
    self->prevMousePos = (sfVector2i){
        self->parent->screenWidth / 2, self->parent->screenHeight / 2};
}

void init_input_defaults(InputClass_t *self)
{
}

void get_input(InputClass_t *self)
{
    sfRenderWindow_setMouseCursorVisible(
        self->parent->render->window, sfFalse);
    sfWindow_setMouseCursorGrabbed(
        (sfWindow *) self->parent->render->window, sfTrue);
    if (sfKeyboard_isKeyPressed(sfKeyW))
        self->forward = 1.0;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        self->forward = -1.0;
    if (sfKeyboard_isKeyPressed(sfKeyA))
        self->strafe = -1.0;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        self->strafe = 1.0;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        self->rotate = -1.0;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        self->rotate = 1.0;
    self->mouse_rot(self);
}

void mouse_rot(InputClass_t *self)
{
    self->currentMousePos = sfMouse_getPositionRenderWindow(NULL);
    self->mouseDistance = self->currentMousePos.x - self->prevMousePos.x;
    if (self->mouseDistance > self->mouseThreshold) {
        self->rotate = 1;
    }
    if (self->mouseDistance < - self->mouseThreshold) {
        self->rotate = -1;
    }
    self->prevMousePos = self->currentMousePos;
}

const InputClass_t input_init = {
    {
        ._size = sizeof input_init,
        ._name = "InputClass_t",
        ._constructor = constructor,
    },
    .get_input = get_input,
    .mouse_rot = mouse_rot,
    .init_input_defaults = init_input_defaults,
};

const class_t *Input = (class_t *) &input_init;
