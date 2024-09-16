#pragma once

#include "framework/string.h"
#include "ecs/entity.h"
#include "ecs/component.h"


typedef enum {
    COMPONENT_POSITION,
    COMPONENT_NAME,
    COMPONENT_N,
} COMPONENT;

COMPONENT_DEFINE(
    name, 
    String text;
)

name *name_get(Entity e);
void name_set(Entity e, String text);

COMPONENT_DEFINE(
    position,
    int x;
)

position *position_get(Entity e);
void position_set(Entity e, int x);
