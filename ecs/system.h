#pragma once

#include "../framework/dynamic_array.h"
#include "entity.h"


typedef struct {
    DynamicArray _entities;
    void (*process)(Entity *);
} System;

System system_create(void (*process)(Entity *));
void system_free(System *system);

void system_add(System *system, Entity *item);
void system_update(System system);
