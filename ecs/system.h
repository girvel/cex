#pragma once

#include "../framework/array.h"
#include "entity.h"


typedef struct {
    Array _entities;
    Array _required_components;
    void (*process)(Entity *);
} System;

System system_create(Array required_components, void (*process)(Entity *));
void system_free(System *system);

bool system_add(System *system, Entity *item);
void system_update(System system);
