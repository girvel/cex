#pragma once

#include "../framework/array.h"


typedef struct {
  Array _components;
} Entity;

Entity entity_create(size_t max_components_n);
void entity_set_component(Entity e, size_t component_id, void *component);
void *entity_get_component(Entity e, size_t component_id);
void entity_free(Entity *e);
