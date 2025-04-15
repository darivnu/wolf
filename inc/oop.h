/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** oop
*/

#include <stdarg.h>
#include <stddef.h>

#ifndef __OOP_H
    #define __OOP_H

typedef void (*constructor_fn_t)(void *, va_list *);
typedef void (*destructor_fn_t)(void *);

typedef struct {
    /* The size of the class */
    size_t _size;
    /* The name of the class */
    const char *_name;
    /* The constructor of the class */
    constructor_fn_t _constructor;
    /* The destructor of the class */
    destructor_fn_t _destructor;
} class_t;

/* Create a new class given a basic description */
void *new_class(const class_t *, ...);

/* Allocate the space needed for a class */
class_t *allocate_class(const class_t *, va_list *);

/* Clean up all resources of a class */
void destroy_class(void *);

/* Used in conjuction with attribute cleanup */
void clean_class(void *);

#endif /* __OOP_H */
