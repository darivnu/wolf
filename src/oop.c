/*
** EPITECH PROJECT, 2025
** minishell1 [WSL: Ubuntu]
** File description:
** oop
*/

#include "../inc/oop.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/common.h"

void *new_class(const class_t *self, ...)
{
    va_list ap;

    va_start(ap, self);
    class_t *class = allocate_class(self, &ap);
    va_end(ap);
    return class;
}

class_t *allocate_class(const class_t *self, va_list *args)
{
    class_t *class = NULL;
    if (self == NULL || self->_size < sizeof(*self)) {
        return NULL;
    }
    class = malloc(self->_size);
    if (!class) {
        return NULL;
    }
    memcpy(class, self, self->_size);
    if (class->_constructor != NULL) {
        class->_constructor(class, args);
    }
    return class;
}

void destroy_class(void *self)
{
    class_t *class = self;
    if (!self) {
        return;
    }
    if (class->_destructor != NULL) {
        class->_destructor(class);
    }
    free(class);
}

void clean_class(void *self)
{
    if (self != NULL) {
        destroy_class(*(class_t **) self);
    }
}
