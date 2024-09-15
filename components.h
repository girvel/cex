#pragma once

#include "framework/dynamic_string.h"


typedef enum {
    COMPONENT_NAME,
    COMPONENT_POSITION,
    COMPONENT_N,
} COMPONENT;

typedef struct {
    String text;
} Name;

typedef struct {
    int x;
} Position;
