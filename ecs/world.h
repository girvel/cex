#pragma once

#include "entity.h"
#include "system.h"
#include "../framework/array.h"


typedef struct {
    Array _all_entities;
    Array _systems;
    int _component_max_id;
} World;

World world_create(int component_max_id);
void world_free(World *world);

Entity world_add_entity(World world);
void world_commit_entity(World *world, Entity *e);
void world_commit_system(World *world, System *s);
void world_update();
