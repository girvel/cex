#pragma once

#include "../framework/array.h"
#include "entity.h"


typedef struct {
    Array _entities;
    void (*process)(Entity *);
} System;

System system_create(void (*process)(Entity *));
void system_free(System *system);

bool system_add(System *system, Entity *item);
void system_update(System system);
