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

Name *name_create(String text);
Name *name_get(Entity e);

typedef struct {
    int x;
} Position;

Position *position_create(int x);
Position *position_get(Entity e);
