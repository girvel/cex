#pragma once

#include "framework/dynamic_string.h"
#include "entity.h"


typedef enum {
    COMPONENT_POSITION,
    COMPONENT_NAME,
    COMPONENT_N,
} COMPONENT;

typedef struct {
    void *_deallocator;
    String text;
} Name;

Name *name_get(Entity e);
void name_set(Entity e, String text);

typedef struct {
    void *_deallocator;
    int x;
} Position;

Position *position_get(Entity e);
void position_set(Entity e, int x);
