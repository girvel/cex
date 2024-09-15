#pragma once

#include "framework/dynamic_string.h"
#include "entity.h"


typedef enum {
    COMPONENT_NAME,
    COMPONENT_POSITION,
    COMPONENT_N,
} COMPONENT;

typedef struct {
    String text;
} Name;

Name *name_get(Entity e);
void name_set(Entity e, String text);

typedef struct {
    int x;
} Position;

Position *position_get(Entity e);
void position_set(Entity e, int x);
